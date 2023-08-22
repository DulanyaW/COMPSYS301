function [retmap, retvisited, retsteps] = dfs(mapfile, startlocation, targetlocation)
    % Load the map and convert it to a matrix
    map = map_convert(mapfile);

    % Initialize visited matrix
    visited = zeros(size(map));

    % Call the recursive DFS function
    [found, path] = recursive_dfs(map, visited, startlocation, targetlocation);

    if found
        retmap = map;
        retvisited = visited;
        retsteps = path;
    else
        retmap = [];
        retvisited = [];
        retsteps = [];
    end
end


% Recursive function for DFS
function [found, path] = recursive_dfs(map, visited, current, target)
    % Check if the current location is the target
    if isequal(current, target)
        found = true;
        path = [current];  % Include the current location in the path
        return;
    end

    visited(current(1), current(2)) = 1;  % Mark the current location as visited

    moves = [1, 0; -1, 0; 0, 1; 0, -1];  % Possible moves: right, left, up, down

    found = false;
    path = [];

    % Iterate through possible moves
    for i = 1:size(moves, 1)
        new_pos = current + moves(i, :);  % Calculate the new position based on the move

        % Check if the new position is within map boundaries and is a valid move
        if new_pos(1) >= 1 && new_pos(1) <= size(map, 1) && ...
           new_pos(2) >= 1 && new_pos(2) <= size(map, 2) && ...
           map(new_pos(1), new_pos(2)) == 0 && visited(new_pos(1), new_pos(2)) == 0
            [found, sub_path] = recursive_dfs(map, visited, new_pos, target);  % Recursive call
            if found
                path = [current, sub_path];  % Include the current location in the path
                return;
            end
        end
    end
end
