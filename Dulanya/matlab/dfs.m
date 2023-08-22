%% This is a shell that you will have to follow strictly. 
% You will use the plotmap() and viewmap() to display the outcome of your algorithm.

% Load sample_data_map_8, three variables will be created in your workspace. These were created as a 
% result of [m,v,s]=dfs('map_8.txt',[14,1],[1,18]);
% The solution can be viewed using 
% plotmap(m,s) 

% write your own function for the DFS algorithm.
function [retmap, retvisited, retsteps] = dfs(mapfile, startlocation, targetlocation)
    % Load the map from the file
    [map] = map_convert(mapfile);

    % Initialize visited matrix
    visited = zeros(size(map));

    % Initialize found flag
    found = false;

    % Keep searching until a path is found
    while ~found
        % Call the recursive DFS function
        [found, steps] = dfs_recursive(map, startlocation, targetlocation, visited, []);

        if ~found
            % If path not found, mark start location as visited to avoid repeating
            visited(startlocation(1), startlocation(2)) = 1;
        end
    end

    % Update map with steps and return the results
    retmap = map;
    retvisited = visited;
    retsteps = steps;

    % Plot the final path
    % plotmap(retmap, retsteps);
end



function [found, steps] = dfs_recursive(map, current, target, visited, path)
    % Check if the current location is the target
    if isequal(current, target)
        found = true;
        steps = [path; current];  % Include the current location in the steps
        return;
    end

    visited(current(1), current(2)) = 1;

    neighbors = get_neighbors(map, current);

    for i = 1:size(neighbors, 1)
        neighbor = neighbors(i, :);
        if ~visited(neighbor(1), neighbor(2))
            [found, steps] = dfs_recursive(map, neighbor, target, visited, [path; current]);
            if found
                return;
            end
        end
    end

    found = false;
    steps = [];
end




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
