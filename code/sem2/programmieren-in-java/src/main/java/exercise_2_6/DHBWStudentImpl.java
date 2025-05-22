package exercise_2_6;

import java.util.Date;

public class DHBWStudentImpl implements DHBWStudent {
    private String dhbwLocation;
    private String studentId;
    private String name;
    private Date birthdate;

    @Override
    public String getDhbwLocation() {
        return dhbwLocation;
    }

    @Override
    public void setDhbwLocation(String dhbwLocation) {
        this.dhbwLocation = dhbwLocation;
    }

    @Override
    public String getStudentId() {
        return studentId;
    }

    @Override
    public void setStudentId(String studentId) {
        this.studentId = studentId;
    }

    @Override
    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public void setBirthdate(Date birthdate) {
        this.birthdate = birthdate;
    }

    @Override
    public Date getBirthdate() {
        return birthdate;
    }
}
