#include "utility.h"

#include "camera.h"
#include"color.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

#include <iostream>


int main() {

	hittable_list world;

	auto material_ground = make_shared<lambertian>(color(0.6,0.5,0.7));
	auto material_center = make_shared<lambertian>(color(0.7,0.4,1.0));
	auto material_left = make_shared<metal>(color(0.7,0.7,1.0), 0.3);
	auto material_right = make_shared<metal>(color(1.0,0.7,0.9), 0.9);

	world.add(make_shared<sphere>(point3(0, 0, -1), 0.5, material_center));
	world.add(make_shared<sphere>(point3(-1.0, 0, -1), 0.5, material_left));
	world.add(make_shared<sphere>(point3(1.0, 0, -1), 0.5, material_right));
	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100, material_ground));

	camera cam;
	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 1600;
	cam.samples_per_pixel = 10;
	cam.max_depth = 10;

	cam.render(world);
}