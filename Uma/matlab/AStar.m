function [map, completePath] = AStar(mapfile, start, target)

%***********Loading and Initialisation**********%


    % Load the map and convert it to a matrix
    map = map_convert(mapfile);  % Load and convert the map from the specified file

    [rows, cols] = size(map);  
    directions = [-1, 0; 1, 0; 0, -1; 0, 1];  % directions: up, down, left, right
    
    openSet = {};  % Initialize nodes to be explored
    cameFrom = containers.Map('KeyType', 'int32', 'ValueType', 'any');  % paths from each node
    wStartToEnd = inf(rows, cols);  % Initialize weight from start to infinity
    wStartToEnd(start(1), start(2)) = 0;  % weight to start node is 0
    
    estimatedWeight = inf(rows, cols);  % Initialize estimated weight to infinity
    estimatedWeight(start(1), start(2)) = heuristic(start, target);  % Estimated weight to endpoint from start
    
    openSet{1} = start;  % Add the start node to the open set



  %***********iteration**********%  
    while ~isempty(openSet)  % Continue until the open set is empty
        estimatedWeights = zeros(size(openSet));
            for i = 1:length(openSet)
                pos = openSet{i};
                estimatedWeights(i) = estimatedWeight(pos(1), pos(2));
            end

        [~, currentIdx] = min(estimatedWeights);

        current = openSet{currentIdx};  % Set the current node to the one with the low estimatedWeights
        
        if isequal(current, target)  % If the current node is the goal node
            path = reconstructPath(cameFrom, target, rows);  % Reconstruct the path from start to target
            completePath = reconstructPath(cameFrom, target, rows);  
            return;  
        end
        
        openSet(currentIdx) = [];  % Remove the current node from the open set
        


        %**********************************************************
        % ****explores its neighbors in all four directions (up, down, left, right).
        %**********************************************************



        for i = 1:size(directions, 1)  % Loop through all directions
            neighbor = current + directions(i, :);  % Calculate the position of neighbor
            
            if isValid(neighbor, rows, cols) && map(neighbor(1), neighbor(2)) == 0  % If the neighbor is valid 
                tempwStartToEndWeight = wStartToEnd(current(1), current(2)) + 1;  % Calculate the  StartToEnd weight for the neighbor
                
                if tempwStartToEndWeight < wStartToEnd(neighbor(1), neighbor(2))  % If the temp weight is better than the current 
                    cameFrom(neighbor(1) * rows + neighbor(2)) = current;  % Update the path from the neighbor to the current node
                    wStartToEnd(neighbor(1), neighbor(2)) = tempwStartToEndWeight;  % Update the weight from start to end for the neighbor
                    estimatedWeight(neighbor(1), neighbor(2)) = wStartToEnd(neighbor(1), neighbor(2)) + heuristic(neighbor, target);  % Update the estimatedWeight for the neighbor
                    
                    if ~containsPosition(openSet, neighbor)  % If the neighbor is not in the open set
                        openSet{end + 1} = neighbor;  % Add the neighbor to the open set 
                    end
                end
            end
        end
    end
    
    path = [];  % No path found
    completePath = [];  % No complete path found
end


%*********************************************************
%*********************calculate hypotenuse(Heuristic)******************

function hypotenuse = heuristic(pos, target)
    hypotenuse = norm(pos - target);  % hypotenuse 
end


%*********************************************************
%*********************Pcheck the position within boundary or not******************

function valid = isValid(pos, rows, cols)
    valid = pos(1) >= 1 && pos(1) <= rows && pos(2) >= 1 && pos(2) <= cols;  % Check if pos is within map boundary
end


%*********************************************************
%*********************Path Reconstruction******************


function path = reconstructPath(cameFrom, current, rows)
    path = current;  % Initialize the path with the current node
    while isKey(cameFrom, current(1) * rows + current(2))  % Traverse the path back using cameFrom map
        current = cameFrom(current(1) * rows + current(2));  % Update current to the previous node
        path = [current; path];  % adds the current node to the beginning of the path
    end
end




%*****************************************************************************
%*********** checks if a given position is present in the open set.**********

function contains = containsPosition(openSet, pos)
    contains = false;  
    for i = 1:numel(openSet)  % Loop (numel-total number of elements in an array)
        if isequal(openSet{i}, pos)  % check - current element is equal to pos
            contains = true;  %  
            break;  
        end
    end
end
