# Manipulator-Model-1
This is a basic Manipulator project for only trail/testing.

Welcome to the development repository for Manipulator Model 1, a 3-DOF (Degrees of Freedom) robotic arm prototype designed to explore the fundamentals of serial manipulators, embedded control, and hardware-software integration.

This repository documents the initial physical prototype phase, its mechanical design files (DXF)

Specifications & Hardware (Model 1)
•	Controller: Arduino Uno R3 
•	Actuation: 3x Servo Servos MG996R (Base Yaw, Shoulder Pitch, Elbow Pitch)
•	Structure: Custom laser-cut acrylic chassis (DXF files included in the /hardware folder)
•	Original Control Scheme: Custom serial-parse protocol accepting raw joint-space instructions (e.g., M1123 to drive Motor 1 to 123 degrees‭‬).

Challenges & Failure Analysis
While Model 1 successfully served as a baseline to verify motor communication and parse basic sequence arrays (STA, STO, PLA), testing revealed critical physical limitations common in rapid-prototyping environments:
	1.	Structural Compliance (Deflection): The laser-cut acrylic chassis exhibited noticeable bending under load. This elasticity introduced geometric errors, rendering precision coordinate-based positioning impossible without rigid materials like aluminum.
	2.	Direct-Drive Joint Stress: Connecting the high-load shoulder and base joints directly to the servo horns subjected the plastic internal gears to severe torsional stress, leading to premature wear.
	3.	Power Spikes: Peak current draws from the servos during simultaneous joint moves occasionally triggered voltage sags on the microcontroller bus, highlighting the need for isolated power distribution and decoupling capacitors.
