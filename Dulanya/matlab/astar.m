function [retmap, retvisited, retsteps] = astar(mapfile, startlocation, targetlocation)
    % Load the map from the file
    [map] = map_convert(mapfile);

    % Initialize visited matrix
    visited = zeros(size(map));

    % Initialize cost and heuristic matrices
    cost = inf(size(map));
    heuristic = zeros(size(map));

    % Initialize open and closed lists
    open_list = [];
    closed_list = [];

    % Add start location to the open list with cost and heuristic values
    cost(startlocation(1), startlocation(2)) = 0;
    heuristic(startlocation(1), startlocation(2)) = manhattan_distance(startlocation, targetlocation);
    open_list = [open_list; startlocation];

    % A* algorithm
    while ~isempty(open_list)
        [~, idx] = min(cost(open_list(:, 1), open_list(:, 2)) + heuristic(open_list(:, 1), open_list(:, 2)));
        current = open_list(idx, :);
        open_list(idx, :) = [];

        if isequal(current, targetlocation)
            break; % Reached the target
        end

        visited(current(1), current(2)) = 1;

        neighbors = get_neighbors(map, current);
        for i = 1:size(neighbors, 1)
            neighbor = neighbors(i, :);
            new_cost = cost(current(1), current(2)) + 1; % Assuming uniform cost
            if new_cost < cost(neighbor(1), neighbor(2))
                cost(neighbor(1), neighbor(2)) = new_cost;
                heuristic(neighbor(1), neighbor(2)) = manhattan_distance(neighbor, targetlocation);
                open_list = [open_list; neighbor];
            end
        end

        closed_list = [closed_list; current];
    end

    % Backtrack to find the path
    path = backtrack_path(closed_list, targetlocation, startlocation);

    % Update map with path and return the results
    retmap = map;
    retvisited = visited;
    retsteps = path;

    % Plot the final path using placestep function
    for i = 1:length(retsteps)
        placestep([retsteps(i,1), retsteps(i,2)], i);
    end
end

% Rest of the functions (manhattan_distance, get_neighbors, is_valid_move) remain the same
function neighbors = get_neighbors(map, location)
    % Define possible moves: up, down, left, right
    moves = [-1, 0; 1, 0; 0, -1; 0, 1];

    neighbors = [];
    for i = 1:size(moves, 1)
        new_location = location + moves(i, :);
        if is_valid_move(map, new_location)
            neighbors = [neighbors; new_location];
        end
    end
end

function valid = is_valid_move(map, location)
    valid = location(1) >= 1 && location(1) <= size(map, 1) && ...
            location(2) >= 1 && location(2) <= size(map, 2) && ...
            map(location(1), location(2)) ~= 0;
end

function placestep(position,i)
% This function will plot a insert yellow rectangle and also print a number in this rectangle. Use with plotmap/viewmap. 
position = [16-position(1) position(2)];
position=[position(2)+0.1 position(1)+0.1];
rectangle('Position',[position,0.8,0.8],'FaceColor','y');
c=sprintf('%d',i);
text(position(1)+0.2,position(2)+0.2,c,'FontSize',10);
end
function distance = manhattan_distance(point1, point2)
    distance = abs(point1(1) - point2(1)) + abs(point1(2) - point2(2));
end
