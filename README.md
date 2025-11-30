# Hostel-Attendance-Management-System
All about management system which can be used in hostel.
                                                                                             AIM of the Project
The aim of this project is to design and develop a simple Hostel/PG Attendance Management System in C language that helps record and manage the daily attendance of students staying in a hostel or PG. The system allows adding student details, marking daily attendance, viewing attendance for a specific date, searching a student’s monthly attendance summary, and generating overall monthly reports using file handling techniques.
                                                                                               ALGORITHM
1. Algorithm for the Overall System (main menu)

Start the program
Display the menu with 7 choices
Read the user’s choice
Use a switch-case to call the respective function:
If choice = 1 → call addStudent()
If choice = 2 → call viewStudents()
If choice = 3 → call markAttendance()
If choice = 4 → call viewAttendanceByDate()
If choice = 5 → call searchStudentAttendance()
If choice = 6 → call generateMonthlyReport()
If choice = 7 → Exit the program
Repeat the menu in a loop until exit
Stop

2. Algorithm: addStudent()

Open file students.txt in append mode
Input student ID
Input student name
Input room number
Write these values to file: ID Name Room
Close the file
Display “Student added successfully”

3. Algorithm: viewStudents()

Open students.txt in read mode
If file does not exist → show message and exit
Read each line from the file:
Extract ID, Name, Room
Display them
Repeat until end of file
Close file

4. Algorithm: markAttendance()

Open students.txt in read mode
Open attendance.txt in append mode
Ask user to enter date
For each student in students.txt:
Display student ID and name
Input attendance status (P/A)
Save record to attendance.txt in format:
date id status
Close both files
Display “Attendance saved successfully”

5. Algorithm: viewAttendanceByDate()

Open attendance.txt in read mode
Open students.txt in read mode
Input date from user
For every record in attendance.txt:
If the date matches the input:
Rewind students.txt to beginning
Search for student with the same ID
Display student name and attendance status
Close both files

6. Algorithm: searchStudentAttendance()

Open attendance.txt in read mode
Input student ID to search
Initialize counters: present = 0, absent = 0
For each attendance record:
If ID matches:
If status = P → increment present
Else increment absent
Display:
Student ID
Present days
Absent days
Close file

7. Algorithm: generateMonthlyReport()

Open students.txt in read mode
Open attendance.txt in read mode
For every student in students.txt:
Reset counters → present = 0, absent = 0
Rewind attendance.txt to beginning
For each attendance record:
If student ID matches:
If status = P → increment present
Else increment absent
Display student name

<img width="1920" height="1080" alt="Screenshot (2)" src="https://github.com/user-attachments/assets/bc0bf966-47a0-47f6-9b14-0095004da2b2" />
<img width="1920" height="1080" alt="Screenshot (1)" src="https://github.com/user-attachments/assets/e3376b24-1f05-44dc-9315-c49c40282dc9" />
<img width="1920" height="1080" alt="Screenshot (3)" src="https://github.com/user-attachments/assets/87266190-e495-4704-813e-9bb6e46a3868" />

