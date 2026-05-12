## Specifications & Hardware

- **Controller:** Arduino Uno R3
- **Transmitter/Receiver:** HC-05 Bluetooth Module
- **Actuation:** 3x Servo Motors MG996R (Base Yaw, Shoulder Pitch, Elbow Pitch)
- **Structure:** Custom laser-cut acrylic chassis (DXF files included)
- **Original Control Scheme:** Custom serial-parse protocol accepting raw joint-space instructions (e.g., `M1123` to drive Motor 1 to 123 degrees).
- **Software:** FreeCAD, Ardiuno IDE, Visual Studio (All software used are open source)
  
## Code Logic:

The HC-05 recieves a set of data via other devices through bluetooth where the device sends a string of data in a specific formate for example "M1120". The data is futher broken in 2 sets, the first 2 character "M1" serves as the Servo ID and the rest tells how much rotation is needed. If the angle is within range of that specific servo ID then it will move slowly to that position else it gives an error.

The code had an array where it could save consequent moves but it often end up glicting/misbehaving. My suspect is the lack of memory the ardiuno have that limits this so i have to remove that part of code.

## Final verdict/review:

I recieved a review from a professional and the issues with this design are
- **Structure:** The servo connected directly to the body can lead to the grinding of gears, a set of planetary gears of lever mechanism can prevent this.
- **Power:** The movement was not very smooth at sometimes and was very jerky and to solve this, couple of capacitors can stablise the power input in the manipulator.
- **Design:** While the design is for testing but acrylic is not good for long term and 3D printing plastic is prefered if available.
- **Precision:** The base motors should be of high torque that can help in precision and stable movement across in heavy loads too, and use of sensor for feedback can improve stability and overall performence significantly.
