package exercise_2_2;

import java.util.ArrayList;
import java.util.List;

public class Course {
    private String courseId;
    private String courseTitle;
    private final List<Student> students;

    public Course(String courseId, String courseTitle) {
        this.courseId = courseId;
        this.courseTitle = courseTitle;
        this.students = new ArrayList<>();
    }

    public String getCourseTitle() {
        return courseTitle;
    }

    public void setCourseTitle(String courseTitle) {
        this.courseTitle = courseTitle;
    }

    public String getCourseId() {
        return courseId;
    }

    public void setCourseId(String courseId) {
        this.courseId = courseId;
    }

    public List<Student> getStudents() {
        return students;
    }

    public void addStudent(Student student) {
        students.add(student);
    }
}
