function viewmap(mapfile, mode)
%Plots the map. See map_convert
% if mode == 0 show walls
% if mode ~= 0 show track

if nargin == 1,
   mode = 0; 
end

map=map_convert(mapfile);
[maprows,mapcols]=size(map);


[X,Y]=meshgrid(1:20,1:20);
plot(X,Y,'k'); hold on
plot(Y,X,'k');
axis([0, mapcols+1, 0, maprows+1]);
axis off


for i=1:maprows,
    for j=1:mapcols,
        if mode == 0,
            if (map(i,j) == 1)
                placeblock([16-i,j]);
            end;
        else
            if (map(i,j) == 0)
                placetrack([16-i,j]);
            end
        end
    end
end

    

%plot row indices
for i = 1:maprows,
   c=sprintf('%d',i); 
   text(0.5,maprows-i+1+0.5,c,'FontSize',8); 
   text(mapcols+1+0.5,maprows-i+1+0.5,c,'FontSize',8); 
end
%plot col indices
for i = 1:mapcols,
   c=sprintf('%d',i); 
   text(0.5+i,maprows+1+0.5,c,'FontSize',8);
   text(0.5+i,0.5,c,'FontSize',8);
end

hold off

end

function placeblock(position)
position=[position(2) position(1)];
rectangle('Position',[position,1,1],'FaceColor','r');
end

function placetrack(position)
position=[position(2) position(1)];
rectangle('Position',[position,1,1],'FaceColor','y');
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

