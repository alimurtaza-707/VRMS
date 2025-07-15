# VRMS - Vehicle Registration Management System
VRMS is a C++ based console application designed to manage vehicle registrations and related entities such as owners, vehicles (cars, bikes, trucks), and administrators in a market environment. It demonstrates fundamental Object-Oriented Programming concepts such as inheritance, polymorphism, encapsulation, and modular design using header and implementation files.

🔧 Features
Add, view, and manage:

Vehicle records (Car, Bike, Truck)

Owner profiles

Admin access

Market and Registration details

File-based data persistence

Object-oriented design with modular C++ classes

/code
  ├── Admin.cpp / Admin.h
  ├── Bike.cpp / Bike.h
  ├── Car.cpp / Car.h
  ├── Truck.cpp / Truck.h
  ├── Vehicle.cpp / Vehicle.h
  ├── Owner.cpp / Owner.h
  ├── Registration.cpp / Registration.h
  ├── Market.cpp / Market.h
  ├── VRMS.cpp / VRMS.h
  ├── main.cpp         ← Entry point of the application
  ├── util.h           ← Utility functions
  ├── VRMS.exe         ← Compiled executable (Windows)


🛠️ Tech Stack
Language: C++

Paradigm: Object-Oriented Programming

Environment: Console application

📝 How to Run
1) Clone the repository:
git clone https://github.com/alimurtaza-707/VRMS.git
cd VRMS/code

2) Compile the code (using g++ or your preferred C++ compiler):
g++ *.cpp -o vrms

3) Run the program:
./vrms   # or vrms.exe on Windows

Refer to Instructions.txt for input formats and sample flows.
