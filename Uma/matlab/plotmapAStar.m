function plotmapAStar(map, steps)
    [X,Y] = meshgrid(1:size(map, 2), 1:size(map, 1));
    plot(X, Y, 'k'); hold on
    plot(Y, X, 'k');
    axis([0, size(map, 2) + 1, 0, size(map, 1) + 1]);
    axis off

    [maprows, mapcols] = size(map);

    for i = 1:maprows
        for j = 1:mapcols
            if map(i, j) == 1
                placeblock([maprows - i + 1, j]);
            end
        end
    end

    % Plot row indices
    for i = 1:maprows
        c = sprintf('%d', i); 
        text(0.5, maprows - i + 1 + 0.5, c, 'FontSize', 8); 
        text(mapcols + 1 + 0.5, maprows - i + 1 + 0.5, c, 'FontSize', 8); 
    end

    % Plot col indices
    for i = 1:mapcols
        c = sprintf('%d', i); 
        text(0.5 + i, maprows + 1 + 0.5, c, 'FontSize', 8);
        text(0.5 + i, 0.5, c, 'FontSize', 8);
    end
    
    if nargin == 2 && ~isempty(steps)
        labelCounter = 1;
        % Reshape the completePath array into a 1xN array
        reshapedPath = reshape(steps.', 1, []);
        for i = 1:2:length(reshapedPath)
            y = reshapedPath(i);
            x = reshapedPath(i + 1);
            placestep([maprows - y + 1, x], labelCounter);
            labelCounter = labelCounter + 1;
            pause(0.1);  % Adjust the duration as needed
        end
    end  
    hold off
end



function placeblock(position)
position=[position(2) position(1)];
rectangle('Position',[position,1,1],'FaceColor','r');
end

function eraseblock(position)
position=[position(2) position(1)];
rectangle('Position',[position,1,1],'FaceColor','w');
end

function placestep(position,i)
position=[position(2)+0.1 position(1)+0.1];
rectangle('Position',[position,0.8,0.8],'FaceColor','y');
c=sprintf('%d',i);
text(position(1)+0.2,position(2)+0.2,c,'FontSize',10);
end

