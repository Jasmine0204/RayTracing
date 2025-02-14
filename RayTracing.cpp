#include "utility.h"

#include "camera.h"
#include"color.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

#include <iostream>


int main() {

	hittable_list world;

	auto material_ground = make_shared<lambertian>(color(0.55, 0.82, 0.63));
	auto material_center = make_shared<lambertian>(color(0.4, 0.96, 0.76));
	auto material_left = make_shared<dielectric>(1.5);
	auto material_right = make_shared<metal>(color(0.62, 1, 1), 0.1);


	world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
	world.add(make_shared<sphere>(point3(0.0, 0.0, -1.0), point3(0.0, 0.3, -1.0), 0.5, material_center));
	world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, material_left));
	world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0),  -0.4, material_left));
	world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, material_right));

	camera cam;
	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 1600;
	cam.samples_per_pixel = 10;
	cam.max_depth = 10;

	cam.vfov = 20;
	cam.lookfrom = point3(-2, 2, 1);
	cam.lookat = point3(0, 0, -1);
	cam.vup = vec3(0, 1, 0);

	cam.defocus_angle = 0;
	cam.focus_dist = 3.4;

	cam.render(world);
}