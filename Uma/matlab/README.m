
% 1s - wall, 0s - track 

% Load the required functions and data
mapfile = 'map.txt';

% %target 1
% startlocation = [14, 1];
% targetlocation = [1, 18];


% %target 1
startlocation = [2, 10];
targetlocation = [6, 6];

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
% Run dfs algorithm
%[retmap,retvisited,retsteps]=dfs(mapfile,[startlocation],[targetlocation]);
% Visualize the complete path using the plotmap function
%plotmap(retmap, retsteps);





