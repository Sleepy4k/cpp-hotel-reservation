# Hotel Reservation

A simple console program to manage hotel reservation like add room hotel, booking room, authentication, etc

## Screenshots  

![App Screenshot](https://cdn.discordapp.com/attachments/790590809169723392/1159652160657698866/image.png?ex=6531cd3c&is=651f583c&hm=2d2d2bed9d3baaa2b5646f49df8f7e33372ef3b0a3bea57bf54128347bbc86ef&)

## Tech Stack  

**Software:** C++

## Features  

- Authentication system
- CSV File
- Unit test

## Lessons Learned  

When i make this software, i learn how to manage memory and optimize software.
Also in this project i use many class i need to manage that all oop,
and learn how to make hashing to encrypt password and important data.

## Run Locally  

Clone the project  

~~~bash  
  git clone https://github.com/Sleepy4k/cpp-hotel-reservation.git
~~~

Go to the project directory  

~~~bash  
  cd cpp-hotel-reservation
~~~

Build the cpp file

~~~bash  
  g++ -std=c++11 ./src/main.cpp  -o ./output/main
~~~

Start the project

~~~bash  
  ./output/main
~~~

If you want to run unit test, build main test file

~~~bash  
  g++ -std=c++11 ./tests/main_test.cpp  -o ./output/main_test
~~~

Start the unit test project

~~~bash  
  ./output/main_test
~~~

Want to run just one command?
run shell script in command prompt for auto execute build command

~~~bash  
  ./build_${project/unit_test}.sh
~~~

## Environment Variables  

To run this project, you will need to add the following environment variables to your windows environment

`g++`

## Acknowledgements  

- [C++ Reference](https://cplusplus.com/reference)

## Feedback  

If you have any feedback, please reach out to us at <sarahpalastrin@gmail.com>

## License  

[MIT](https://github.com/Sleepy4k/cpp-hotel-reservation.git/blob/main/LICENSE)
