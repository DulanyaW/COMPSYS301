
% Load the required functions and data
mapfile = 'map_8.txt';
startlocation = [2, 16];
targetlocation = [14, 1];


%****************************************************************************%

% 
% Run AStar
[map, completePath]= AStar(mapfile, [startlocation],[targetlocation])

% Visualize the complete path using the plotmap function
plotmapAStar(map, completePath);



%****************************************************************************%
%  % Load the map and convert it to a matrix
%  map = map_convert(mapfile);
% 
% % Run Dijkstra's algorithm
% [retmap, retvisited, retsteps] = dijkstra(map, startlocation, targetlocation)
% 
% disp(retsteps);
% 
% 
% % Plot the map with the path
% plotmap(map, retsteps);




%****************************************************************************%
% % Run dfs algorithm
% [retmap,retvisited,retsteps]=dfs(mapfile,[startlocation],[targetlocation]);
% % Visualize the complete path using the plotmap function
% plotmap(retmap, retsteps);


