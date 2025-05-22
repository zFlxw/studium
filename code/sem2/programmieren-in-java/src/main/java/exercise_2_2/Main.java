package exercise_2_2;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Course> courses = new ArrayList<>();
        for (int i = 0; i < args.length; i++) {
            if (i < 6) {
                String id = args[i];
                String name = args[i + 1];
                courses.add(new Course(id, name));
                i++;
            } else if (i + 4 < args.length) {
                Student student = new Student(args[i], args[i + 1]);
                int finalI = i;
                courses.stream().filter(course -> course.getCourseId().equals(args[finalI + 2])).findFirst().get().addStudent(student);
                courses.stream().filter(course -> course.getCourseId().equals(args[finalI + 3])).findFirst().get().addStudent(student);
                i += 3;
            }
        }

        for (Course course : courses) {
            System.out.println("Course ID: " + course.getCourseId());
            System.out.println("Course Name: " + course.getCourseTitle());
            for (Student student : course.getStudents()) {
                System.out.println("- " + student.getStudentId() + ": " + student.getName());
            }

            System.out.println("---------");
        }
    }
}