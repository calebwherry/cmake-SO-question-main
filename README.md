cmake-SO-question-main
========================

Test for stackoverflow question: http://stackoverflow.com/q/27261288/408160

### Update 12/9/2014

Riddle solved! Solution copied from SO question to have it documented here:

----------------------

Took awhile but I have finally arrived at an answer with help from the CMake Users listserv, specifically @brad-king.

The main issue is that I am not compiling my shared object correctly in my external project. Brad's answer to my question:

> Thanks for the complete/simple example. The problem is that the libExtLib.so file built by the external project does not 
> have DT_SONAME set by the linker. When a linker is given a path to a shared library file that has no soname then the path 
> is copied into the DT_NEEDED field of the consumer since it has no soname to use for that.
> 
> There are two solutions:
>
> 1. Make sure DT_SONAME gets set properly by the external build system.
> 2. Tell CMake that the imported library file has no soname:<br>
> set_property(TARGET ExtLib PROPERTY IMPORTED_NO_SONAME 1)
> 
> CMake will then link it via -lExtLib and the linker will not store the path to the file in DT_NEEDED but only the file
> name.
> 
> Either of these should resolve the issue. Number 1 is cleaner.

Since I have control over the Make files in the external library, I opted for the cleaner first solution by compiling the shared object like so:

```cpp
$(SHARED_TARGET): $(OBJECTS)
     $(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS) -Wl,-soname,$@
```

I have revised my original example and made it a lot simpler: https://github.com/calebwherry/cmake-SO-question-main. I will leave it up as a reference for anyone stumbling across this post at a later date.

**P.S.**

There is another fix that is sub-optimal. If I hadn't done any of the above, I could have just given target_link_library the full path to the library I was linking against and not used the imported library target. I have noted this in the CMake file in the repo and commented it out. Not a great solution but does solve the issue another way.
