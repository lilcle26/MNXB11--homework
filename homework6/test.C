#include <MovingObject.h>
#include <iostream>

void test() {
    MovingObject object(0.30, 0.40, 0.00);
    std::cout << object.Vx() << object.Vy() << object.Vz() << std::endl;
    std::cout << object.Speed() << object.HorizontalSpeed() << std::endl;
    object.SetVelocity(0.30, 0.40, 0.50);
    std::cout << object.Vx() << object.Vy() << object.Vz() << std::endl;
    std::cout << object.Speed() << object.HorizontalSpeed() << std::endl;
}
