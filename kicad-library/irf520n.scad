width = 10.54;
height2 = 15.24;
height1 = height2 - 6.47;
depth = 4.69;
indent = 0.5;
pin_length = 14.09;
metal_thickness = 1.32;

module metal() {
	small_circle_radius = 2.87 / 2 / 2;

	linear_extrude(height=metal_thickness) {
		difference() {
			square([10.54,height2]);
			translate([5.27,height2-2.87]) circle(3.78/2, $fn=200);
			translate([0,height2-2.87+small_circle_radius]) circle(small_circle_radius, $fn=200);
			translate([width,height2-2.87+small_circle_radius]) circle(small_circle_radius, $fn=200);
		};
	};
};

module casing() {
	polyhedron(
		points=[
			// Back
			[0,0,metal_thickness],[0,height1,metal_thickness],
			[width,height1,metal_thickness],[width,0,metal_thickness],
			// Front
			[0+indent,0,depth],[0+indent,height1-indent,depth],
			[width-indent,height1-indent,depth],[width-indent,0,depth]
		],
		faces=[[0,3,2,1],[4,5,6,7],[0,1,5,4],[1,2,6,5],[3,7,6,2],[0,4,7,3]]
	);
};

module pins() {
	pin_width = 1.4;
	center = (width / 2) - (pin_width / 2);
	distance = 2.54;

	translate([center-distance,-pin_length,0]) cube([pin_width,pin_length,0.55]);
	translate([center,-pin_length,0]) cube([pin_width,pin_length,0.55]);
	translate([center+distance,-pin_length,0]) cube([pin_width,pin_length,0.55]);
};

module everything() {
	union() {
		metal();
		casing();
		pins();
	};
};


rotate(a=[90,0,0]) everything();