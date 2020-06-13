# C/C++ Stuff

## Some programs utilize google testing found here: 
[Google testing](https://github.com/google/googletest).

## Setup in netbeans
1. Download and extract google testing files
2. Create static project in netbeans
3. Right click main project folder, go to project properties -> c++ compiler -> include directory and add googletest folder and include folder
4. Add gtest_main and gtest-all source files into source folder of project
5. Build the project
6. Create main project that will be tested
7. Create a new test folder under Test Files folder
8. Right click on new folder, go to project properties -> c++ compiler -> include directory and add googletest folder and include folder
9. Right click on new folder again, go to project properties -> linker -> libraries and add project directory of project created in second step
10. Create a new source file under the new folder and write tests here
11. Right click folder and click Test
