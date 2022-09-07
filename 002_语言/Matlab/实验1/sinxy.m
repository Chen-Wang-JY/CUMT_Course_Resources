[x,y]=meshgrid(-2*pi:0.02:2*pi);
z=sin(x.*y);
mesh(x,y,z);