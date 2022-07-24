# Archisman-Roy-Hardware-Project
Density based traffic control system


Components of this project - Arduino UNO , 2x2 LED lights for the signals(Red, Green) , 2 breadboards , 2 Ultrasonic sensors 

I have used 2 traffic signals in this project representing a two signal intersection. The ultrasonic sensors detects objects in its path and determines the distance by the formula used in the code attached. I have used this distance as a measure of vehicle density . A smaller distance  represents a higher vehicle density and vice versa.

After calculating these distances  the code compares them and determines the smallest among them. The red signal is turned on for the lane having a lower vehicle density and green signal for the higher one allowing the flow of traffic.
