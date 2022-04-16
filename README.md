# FDF
# ALGORITHM:
this project took me some serious time to do but here i am explaining how i did it .</br>

so the basics of this project is to draw a line on the screen using a C Library named "MiniLibX" u can find its docummentation here : https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html </br>

i used an algorithm in which we will take a point "p0(x0, y0)" as a default point with whome we're going to start drawing,</br>

"BS : you will have to give the point p0 default coordinations for example p0(50, 50). "</br>

and of course to draw a line we need two points, so now we're looking for our second point "p1(x1, y1)" </br>

<img width="1241" alt="Screen Shot 2022-04-16 at 10 14 57 PM" src="https://user-images.githubusercontent.com/65429355/163692982-eb9cd888-9e60-42c6-ac78-62eaa064803e.png">
</br>

in the picture above we see that we've formed a triangle using the line that we want to draw, which is the distance between p1 and p0, Dx which </br>
is the difference between x1 and x0 "x1 - x2", and finally Dy which is the difference between y1 and y0 "y1 - y0".</br>
and in that moment it pops up to my mind that i can get the "TAN" of the angle showed above using Dx and Dy as i showed in the picture.
