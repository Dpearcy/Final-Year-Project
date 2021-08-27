# Final-Year-Project
This is David's Pearcy 3rd Year Project was about ray tracing on CPU and making render  at a frame-rate. 

The Code Was good a soild 2nd when marked in December 2018 but as my report was rushed I finshed a 3rd.//// not sure If to keep.
The .Cpp and .H files are all bar two is made by me, That one being Veator3.h and.cpp mostly made by graphics lecturer and then changed by me. 

////What I did and how my raytracing works 

////How need to way more technical go into the maths
My ray tracer works by for each pixel I fire a ray from a pixel into the world space, If the ray hits something the that color is stored
and then appied to the pixel to displayed to the screen.
As the Ray is fired and the pixel caluations are all done the CPU in C++ and does nothing on GPU. But as the rander is built to in Classes and OOP,
It can be moved to DOP.
I started with just firing into the world. the next step was making a sphere the ray could hit.
The maths behind this is as follows: getting O + tD  O = orgin of ray, t = point along the a ray, D = direction of the ray(nomalized)
we need to find point of entry and exit
 next step right-angled triangle of centre of sphere we will C and O so now  simple  L = C - O, Tca = dot(L,D); now we use Pythagorean theorem 
so that means d2 + T2ca = L2 d = scrt(L2−t2ca) = scrt(L∙L−tca∙tca)
finally d2+t2hc=radius2  thc= scrt(radius2−d2)  t0=tca−thc   t1=tca+thc t0 is the point of entry to sphere and t1 is point of exit to sphere.
the final color appied to the window at load. DirectX is never used. 


The pictures below are of finished product and the different scenes. 
![bandicam 2019-04-06 21-34-03-430](https://user-images.githubusercontent.com/44159287/109843636-3217b680-7c43-11eb-86cd-9760905c9404.jpg)
![bandicam 2019-04-06 21-52-41-295](https://user-images.githubusercontent.com/44159287/109843707-4491f000-7c43-11eb-9040-ae1cfc9d19cc.jpg)
![bandicam 2019-04-06 21-54-10-299](https://user-images.githubusercontent.com/44159287/109843718-48257700-7c43-11eb-8c30-fff05c886bca.jpg)
