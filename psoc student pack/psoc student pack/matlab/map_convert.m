function [map] = map_convert( mapfile )


%% Read map file and construct a matrix
% '1' is where robot cannot go, '0' is where it can
t1=textread(mapfile,'%s');
[r,c]=size(t1);

%map dimensions
rows = r;
cols = length(t1{1});
map=ones(rows,cols);

for i=1:r,
  line = t1{i};
  for j = 1:cols,
      map(i,j) = line(j)-'0';
  end;
end



end

