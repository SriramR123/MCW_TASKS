from abc import ABC, abstractmethod

class VehicleType(ABC):
    #Abstract Parent class for vehicle type selection.

    def __init__(self):
        self.__vehicle_type = None

    @abstractmethod
    def select_vehicle_type(self):
        pass

    def get_vehicle_type(self):
        return self.__vehicle_type

    def set_vehicle_type(self, vehicle_type):
        self.__vehicle_type = vehicle_type

class Car(VehicleType):
    #Class for car-related options.

    def __init__(self):
        super().__init__()
        self.__car_type = None
        self.__engine_type = None
        self.__fuel_type = None
        self.__capacity_or_battery = None
        self.__range_or_mileage = None

    def select_vehicle_type(self):
        while True:
            print("\nSelect Vehicle Type:")
            print("1. Car")
            print("2. Bike")
            print("3. Truck")
            print("4. Others")
            print("5. Exit")

            choice = input("Enter your choice (1-5): ")

            if choice == "5":
                print("Exiting the program. Thank you!")
                exit()
            elif choice == "1":
                self.set_vehicle_type("Car")
                break
            else:
                print("Invalid choice. Currently, only the 'Car' option is supported.")

    def select_car_type(self):
        while True:
            print("\nSelect Car Type:")
            print("1. Sedan")
            print("2. SUV")
            print("3. Hatchback")

            car_type_choice = input("Enter your choice (1-3): ")

            if car_type_choice == "1":
                self.__car_type = "Sedan"
                break
            elif car_type_choice == "2":
                self.__car_type = "SUV"
                break
            elif car_type_choice == "3":
                self.__car_type = "Hatchback"
                break
            else:
                print("Invalid choice. Please try again.")

    def select_car_options(self):
        self.select_car_type()

        while True:
            print("\nSelect Engine Type:")
            print("1. IC Engine")
            print("2. EV Engine")

            engine_choice = input("Enter your choice (1-2): ")

            if engine_choice == "1":
                self.__engine_type = "IC Engine"
                self.select_ic_engine_options()
                break
            elif engine_choice == "2":
                self.__engine_type = "EV Engine"
                self.select_ev_engine_options()
                break
            else:
                print("Invalid choice. Please try again.")

    def select_ic_engine_options(self):
        while True:
            print("\nSelect Fuel Type:")
            print("1. Petrol")
            print("2. Diesel")

            fuel_choice = input("Enter your choice (1-2): ")

            if fuel_choice == "1":
                self.__fuel_type = "Petrol"
                break
            elif fuel_choice == "2":
                self.__fuel_type = "Diesel"
                break
            else:
                print("Invalid choice. Please try again.")

        while True:
            print("\nAvailable Engine Capacities (in CC): 1000, 1500, 2000")
            capacity = input("Select Engine Capacity: ")

            if capacity in ["1000", "1500", "2000"]:
                self.__capacity_or_battery = capacity
                break
            else:
                print("Invalid capacity. Please select a valid option.")

        while True:
            print("\nAvailable Mileage Options (in km/l): 15, 20, 25")
            mileage = input("Select Mileage: ")

            if mileage in ["15", "20", "25"]:
                self.__range_or_mileage = mileage
                break
            else:
                print("Invalid mileage. Please select a valid option.")

    def select_ev_engine_options(self):
        while True:
            print("\nAvailable Battery Capacities (in kWh): 40, 60, 80")
            battery_capacity = input("Select Battery Capacity: ")

            if battery_capacity in ["40", "60", "80"]:
                self.__capacity_or_battery = battery_capacity
                break
            else:
                print("Invalid battery capacity. Please select a valid option.")

        while True:
            print("\nAvailable Range Options (in km): 200, 300, 400")
            range_option = input("Select Range: ")

            if range_option in ["200", "300", "400"]:
                self.__range_or_mileage = range_option
                break
            else:
                print("Invalid range. Please select a valid option.")

    def get_car_details(self):
        return {
            "car_type": self.__car_type,
            "engine_type": self.__engine_type,
            "fuel_type": self.__fuel_type,
            "capacity_or_battery": self.__capacity_or_battery,
            "range_or_mileage": self.__range_or_mileage,
        }

class PriceCalculator(Car):
    #Class to calculate the price based on selected options.

    def __init__(self):
        super().__init__()
        self.__price = 0

    def calculate_price(self):
        details = self.get_car_details()

        if self.get_vehicle_type() == "Car":
            if details["engine_type"] == "IC Engine":
                if details["fuel_type"] == "Petrol":
                    self.__price = int(details["capacity_or_battery"]) * 1000 + int(details["range_or_mileage"]) * 50
                elif details["fuel_type"] == "Diesel":
                    self.__price = int(details["capacity_or_battery"]) * 1200 + int(details["range_or_mileage"]) * 60
            elif details["engine_type"] == "EV Engine":
                self.__price = int(details["capacity_or_battery"]) * 1500 + int(details["range_or_mileage"]) * 30

    def print_estimate(self):
        details = self.get_car_details()

        print("\n--- Cost Estimate ---")
        print(f"Vehicle Type: {self.get_vehicle_type()}")
        if self.get_vehicle_type() == "Car":
            print(f"Car Type: {details['car_type']}")
            print(f"Engine Type: {details['engine_type']}")
            if details["engine_type"] == "IC Engine":
                print(f"Fuel Type: {details['fuel_type']}")
                print(f"Engine Capacity: {details['capacity_or_battery']} CC")
                print(f"Mileage: {details['range_or_mileage']} km/l")
            elif details["engine_type"] == "EV Engine":
                print(f"Battery Capacity: {details['capacity_or_battery']} kWh")
                print(f"Range: {details['range_or_mileage']} km")
        print(f"Estimated Price: ₹{self.__price}")

# Main Program
if __name__ == "__main__":
    price_calculator = PriceCalculator()
    price_calculator.select_vehicle_type()

    if price_calculator.get_vehicle_type() == "Car":
        price_calculator.select_car_options()
        price_calculator.calculate_price()
        price_calculator.print_estimate()
    else:
        print("Unable to proceed with the selected vehicle type.")
