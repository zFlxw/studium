package exercise_2_6;

import java.util.Date;

public class PersonImpl implements Person {
    private String name;
    private Date birthdate;

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
