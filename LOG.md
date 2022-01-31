# 09/01/22

Today I finally finished the mat4 inverse function. The thing that was causing me
issues was the fact that the cofactor matrix doesn't alternate on every other
element but instead it's a checkerboard (obviously). Instead of getting all the
affine transformation functions done, I implemented some testing and benchmarking
utilities. I'm super pleased with the actual .c code but I also made a couple
scripts for automatically running all the tests and I'm not sure if I like that.
I think tomorrow I'm gonna end up scrapping the ./gentests script and just
manually do it. I think it's cleaner that way. I could also research dynamic
lookup and just do it like that but it's not a cross-platform solution even
though it is pretty .c code. Tomorrow I'm gonna finish up the testing suite and
actually get to work on the transformation code. I also am gonna start backing up
my work by just copying the folder (I had a couple scares today). I really should
just upload it to git though...

# 08/01/22

Today I've implemented all the functions for vec2-4 and mat2-3. I've been
struggling with making the inverse function for mat4. Tomorrow I'll bang out
EMat4Inverse and then make the transform.h. The transform.h will have all the
functions for making transformation matrices e.g. rotations, scales,
translations. I'll also implement the vector rotation functions i.e.
EVec3Rotate. I also want to make sure all my other inverse functions work
properly. I also want to see if I can optimise any of the maths.
