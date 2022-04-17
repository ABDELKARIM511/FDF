# FDF
# ALGORITHM:
<h2>this project took me some serious time to do but here i am explaining how i did it .</h2>
</br>
<h3>1 - HOW TO DRAW A LINE ON THE SCREEN :</h3>
The basics of this project is to draw a line on the screen using a C Library named "MiniLibX" you can find its docummentation <a href="https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html">here</a>.</br>

<p>I worked on an algorithm in which we will take a default point "p0(x0, y0)" that we'll use to start drawing.<b>"this point is a known point."</b></br>
<ul>
  <li> To draw a line we need two points, so now we're looking for our second point "p1(x1, y1)".</li>
  <li> You will have to give the point p0 default coordinations for example p0(50, 50). </li>
</ul>
</br>
</p>

<img width="1241" alt="Screen Shot 2022-04-16 at 10 14 57 PM" src="https://user-images.githubusercontent.com/65429355/163692982-eb9cd888-9e60-42c6-ac78-62eaa064803e.png">
</br>
<p>
in the picture above we see that we've formed a triangle using :
 <ul>
   <li>the line that we want to draw which is the distance between p1 and p0.</li>
   <li>Dx which is the difference between x1 and x0 "x1 - x0".</li>
   <li>Dy which is the difference between y1 and y0 "y1 - y0".</li>
 </ul>
 </br>
in that moment it pops up to my mind that i can get the "tangent" of the angle showed above using Dx and Dy as i showed in the picture "tan(a) = Dy / Dx".</br>
and finally i'll end up with my line equation that i surrounded in the picture above.
</p>
<p>
  Now, that i finally got my equation line all i have to do is to give a default value for my tangent so that i can get a curved line.</br>
  in my project i took a tangent of: 
  <ol>
     <li>"0.1" as a default value to draw my horizontal lines "check on draw.c".</li>
     <li>"3" as a default value to draw my vertical lines "check on draw2.c".</li>
  </ol>
  Now, we have our equations all we have to do is to give x1 in p1(x1, y1) a value, start drawing from x1 = x0 and keep going til the x1's new value and you will end up with a line on the screen.
</p>
<h3>2 - HOW TO DRAW THE THIRD DIMENSION MAP:</h3>
<img width="587" alt="Screen Shot 2022-04-16 at 11 50 18 PM" src="https://user-images.githubusercontent.com/65429355/163694648-40952347-8d53-4cc9-bf66-6008f6cbacb8.png"></br>
Drawing the third dimension wasn't the hardest part of this project because all i had to do is draw my lines as usual but this time </br>
i had to give the illusion that it's a 3D map.</br>
as i showed above this is the kind of map i'm drawing, the numbers show "Z" the third dimension while "X" and "Y" are presented by the position of each number on the map.</br>
</br>
<b>'0' means that this point on the map is straight on the floor, '10' means that the point is up from the floor by 10 pixel and so on...</b></br></br>


<img width="1234" alt="Screen Shot 2022-04-17 at 12 00 47 AM" src="https://user-images.githubusercontent.com/65429355/163694838-348a21a9-e7a5-46a6-893a-61e137fd4a2d.png">
</br>
and now all i did is drawing my map as if all the "Z"s equal 0 and then for each "Z" who equals 10 i make it's x = x + 10 and y = y - 10
</br>
For example :
<ul>
  <li>p0(50, 50) => x0 = 50 and y0 = 50</li>
  <li>p1(100, 55) => x1 = 100 and y1 = 55 </li>
</ul>
if p1's z = 10 and p0's z = 0 it will be like :
<ul>
  <li>p0(50, 50) => x0 = 50 + 0 and y0 = 50 - 0 </li>
  <li>p1(100, 55) => x1 = 100 + 10 = 110 and y1 = 55 - 10 = 45</li>
</ul>
so the actual coordinations of p1 will be: p1(110, 45)
<h3>SOME PLEASANT TO THE EYE RESULTS :</h3></br>
</br>
<img width="1809" alt="Screen Shot 2022-04-17 at 12 20 05 AM" src="https://user-images.githubusercontent.com/65429355/163695331-9afa79a9-c1c2-46b7-9c96-36e4e41f6196.png">
</br>
</br>
<img width="1904" alt="Screen Shot 2022-04-17 at 12 28 27 AM" src="https://user-images.githubusercontent.com/65429355/163695335-2c08a038-1fa3-468f-93f1-161a5f9a2fe6.png">
</br>
</br>
<img width="1866" alt="Screen Shot 2022-04-17 at 12 28 59 AM" src="https://user-images.githubusercontent.com/65429355/163695342-7a0974c3-932b-4e3a-ae6a-ab292d9a30f7.png">
</br>
</br>
<img width="1844" alt="Screen Shot 2022-04-17 at 12 31 34 AM" src="https://user-images.githubusercontent.com/65429355/163695347-16ad4406-0915-4350-be74-271702d6b4e5.png">
