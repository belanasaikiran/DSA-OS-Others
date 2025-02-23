import java.util.ArrayList;
import java.util.List;

public class Vehicle {

    public Integer getNumberOfWheels() {
        return 2;
    }

    public Boolean hasEngine() {
        return true;
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

    @Override
    public Boolean hasEngine() {
        return false; // This is the violation of Liskov Substitution Principle
    }
}

public class Main {

    public static void main(String[] args) {
        List<Vehicle> vehicleList = new ArrayList<>();
        vehicleList.add(new MotorCycle());
        vehicleList.add(new Car());
        vehicleList.add(new Bicycle()); // This will cause issues

        for (Vehicle vehicle : vehicleList) {
            System.out.println(vehicle.hasEngine().toString()); // This will cause issues because Bicycle does not have an engine
        }
    }
}
