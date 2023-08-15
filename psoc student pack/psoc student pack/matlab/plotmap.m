function plotmap(map,steps)
%Plots the map. See map_convert

[X,Y]=meshgrid(1:20,1:20);
plot(X,Y,'k'); hold on
plot(Y,X,'k');
axis([0, 20, 0, 16]);
axis off
[maprows,mapcols]=size(map);

for i=1:maprows,
    for j=1:mapcols,
       if (map(i,j) == 1)
           placeblock([16-i,j]);
       end;
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

if (nargin == 2)
    if (length(steps)>0),
        for i=1:length(steps),
            placestep([16-steps(i,1) steps(i,2)],i);
        end
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

