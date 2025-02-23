import java.util.ArrayList;
import java.util.List;

public class Vehicle {

    public Integer getNumberOfWheels() {
        return 2;
    }
}

public class MotorCycle extends Vehicle {

    @Override
    public Integer getNumberOfWheels() {
        return 2;
    }
}

public class Car extends Vehicle {

    @Override
    public Integer getNumberOfWheels() {
        return 4;
    }
}

public class Bicycle extends Vehicle {

    @Override
    public Integer getNumberOfWheels() {
        return 2;
    }

    public Boolean hasEngine() {
        return false;
    }
}

public class Main {

    public static void main(String[] args) {
        List<Vehicle> vehicleList = new ArrayList<>();
        vehicleList.add(new MotorCycle());
        vehicleList.add(new Car());
        vehicleList.add(new Bicycle());

        for (Vehicle vehicle : vehicleList) {
            System.out.println(vehicle.hasEngine().toString()); // Now, Instead of null pointer exception, we get error at compile time.
    }
}
