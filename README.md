# Sunflower Optimization Algorithm (SFO)

# English

SFO (Sunflower Optimization) is an algorithm that mimics the behavior of sunflowers. Sunflowers always face the sun, and if they can't find it, they go back to their original position. The details are as follows:

=========Biological and Natural Behavior=========
Sunflowers move towards the strongest source of light. This can be calculated using the following mathematical formula:

	I = P/(4pid^2)
	
where I is the intensity of sunlight, P is the power of the sun, and d is the distance between the sun and the sunflower.

=========Adjusting the Orientation of Sunflowers=========
Each sunflower adjusts its orientation towards the sun as shown in the following equation:

	S(i) = X* - Xi / ||X* - Xi||
	
where X* is the global best solution, Xi is the current solution, and n is the population size.

=========Facing the Sun=========
Each sunflower faces the sun according to the following equation:

	di = Y(angle) * Pi( ||Xi + Xi-1|| * ||Xi + Xi-1|| )
	
where Y(angle) is the angle of the sunflower, and Pi( ||Xi + Xi-1||) is the probability of pollination between the nearest sunflowers. This generates a new sunflower based on the distance between the two sunflowers.

=========Limiting the Sunflower's Range=========
Each sunflower's position is limited to the following formula:

	d(max) = || X(max) - X(min) || / 2 * n
	
where X(max) and X(min) are the maximum and minimum limits, and n is the population size.

=========Updating the Sunflower's Position=========
Each sunflower changes position to create a new sunflower in the following equation:

	X(i+1) = X(i) + d(i) * s(i)
	
where Xi+1 is the position of the new sunflower (individual).

=========Algorithm Guidelines=========
The algorithm for improving sunflowers' efficiency is as follows:

	Set the initial parameters for the death rate (m), population size (n), pollination rate (P), and maximum iteration (mazitr), e.g., m = 1, n = 50, P = 20, mazitr = 80.
	Set t = 0.
	Create a population of sunflowers X(i) E (L,U] randomly, where i = 1,2,3,...,n, similar to the genetic population, or we can set population = n.
	Evaluate the fitness function of each sunflower in the population X.
	Select the best sunflower from the overall population X.
	Adjust all sunflowers' position towards the sun as shown in equation 5.
	While True:
		Calculate the movement direction of the fitness function as a vector for all individuals.
		Remove the worst m% of sunflowers.
		Calculate the process of individuals moving towards the sun as shown in equation 6.
		Fertilize the best sunflowers in this round of sun.
		Check the maximum value, as shown in item 7.
		Update the data as shown in item 8.
		Evaluate new individuals.
		Accept new individuals if their fitness value is better than the current value.
		Set t = t+1.
	If t > mazitr, exit the loop.
	Display the best result.


# ภาษาไทย

SFO คือ Algorithm ที่เลียนแบบพฤติกรรมของดอกทานตะวัน โดยดอกทานตะวันจะหันหน้าเข้าหาแสงอาทิตย์เสมอ และจะกลับไป set home เมื่อดอกทานตะวันหาดวงอาทิตย์ไม่เจอ รายละเอียดดังนี้

=========พฤติกรรมทางชีวภาพและธรรมชาติ=========
จะเคลื่อนที่เข้าหาแสงที่มีความเข็มแสงมากที่สุดโดยเราสามารถคำนวณได้โดย ใช้สูตรทางคณิตศาสตร์ ดังนี้

	I = P/(4*pi*d^2)

เป็นสูตรในการหาความเข้มของแสงโดยเฉพาะ โดยที่
I คือความเข้มของการแผ่รังสีดวงอาทิตย์
P คือพลังของดวงอาทิตย์ 
d คือระยะห่างระหว่างดวงอาทิตย์กับดอกทานตะวันแต่ละดวง

=========การปรับทิศทางดอกทานตะวัน=========
ดอกทานตะวันแต่ละดอกจะปรับทิศทางของมันไปที่ ดวงอาทิตย์ดังแสดงในสมการต่อไปนี้

    S(i) = X* - Xi / ||X* - Xi||      i = 1,2,.....,n

โดยที่
X* คือคำตอบที่ดีที่สุดโดยรวม 
Xi คือคำตอบปัจจุบัน
n คือขนาดประชากร

ขั้นตอนต่อมา ดอกทานตะวันจะหันเข้าหาดวงอาทิตย์ มีแสดงดังนี้

	di = Y(มุม) * Pi( ||Xi + Xi-1|| * ||Xi + Xi-1|| )

โดยจะมี
Y(มุม) = มุมความเฉื่อยของดอกทานตะวัน
Pi( ||Xi + Xi-1||)  = ความน่าจะเป็นของการผสมเกสรที่ดอกทานตะวันแต่ละชนิดของดอกทานตะวัน กับดอกทานตะวันที่อยู่ใกล้ที่สุด เพื่อสร้างดอกทานตะวันใหม่ในตำแหน่งใหม่โดยพิจารณาจากระยะห่างระหว่างดอกทานตะวันทั้งสองตัว

และสุดท้าย คือ การกำหนดลิมิตของดอกทานตะวันแต่ละขั้นถูกจำกัดไม่ให้เกินค่าต่อไปนี้
ด้วยสูตร

    d(max)  = || X(max) - X(min) || / 2 * n

โดยที่ X(max) และ X(min) เป็นลิมิตที่มากที่สุดและลิมิตที่น้อยที่สุด 
n คือ จำนวนประชากรของดอกทานตะวัน



=========อัพเดทตำแหน่งดอกทานตะวัน=========
ดอกทานตะวันแต่ละชนิด มีการเปลี่ยนตำแหน่งเพื่อผลิตดอกทานตะวันรุ่นใหม่ตามทิศทาง ( ขึ้นตก Sun )
และขั้นตอนของดอกทานตะวันที่มุ่งสู่ดวงอาทิตย์ ( การหันหน้าเข้าหาดวงอาทิตย์ )ดังนี้
โดยใช้สูตร

    X(i+1)  = X(i) + d(i) * s(i)
    
โดยที่ Xi+1 คือตำแหน่งของดอกทานตะวันที่สร้างขึ้นใหม่ (รายบุคคล)


# แนวทางการเขียนโค้ด
อัลกอริธึมการเพิ่มประสิทธิภาพดอกทานตะวัน
1: ตั้งค่าเริ่มต้นสำหรับอัตราการตาย m, ขนาดประชากร n, อัตราการผสมเกสร P และจำนวนการวนซ้ำสูงสุด mazitr เช่น m = 1 ; n = 50 ; P = 20 ; mazitr = 80

2: ตั้งค่า t = 0

3: สร้างประชากร X(i) E (L,U] แบบสุ่ม ,  i = 1,2,3,...,n
จะคล้ายกับในส่วนของ Genetic หรือเราสามารถปรับได้เป็น 
population = n

4: การทำประเมิน Fitness Function รายต้นของดอกทานตะวัน ในประชากรที่เรากำหนดไว้ทั้งหมด
ประเมินสมรรถภาพร่างกายของบุคคล (ทานตะวัน) ในประชากร 1,.. ,n. = S(X).

5: เลือกดอกที่ดีที่สุดจากโดยรวมของประชากร X

6: ปรับบุคคลทั้งหมด (ดอกทานตะวัน) ปรับตำแหน่งไปทางดวงอาทิตย์ ดังแสดงในสมการที่ 5

7: While Ture:

	8 : คำนวณทิศทางการเคลื่อนที่ ของค่า Fitness เป็นรูปแบบเวกเตอร์ ให้กับทุกประชากร

	9: ลบดอกไม้ที่มีค่าแย่ที่สุดออกไป ค่า m%

	10: คำนวณขั้นตอนของบุคคลเข้าหาดวงอาทิตย์ดังในข้อที่ 6

	11: ให้ปุ๋ยดอกทานตะวันที่ดีที่สุดรอบดวงอาทิตย์

	12: ตรวจสอบค่าที่มากที่สุด ตามที่แสดงในข้อที่ 7

	13: อัพเดตข้อมูล ดังข้อที่ 8

	14: ประเมินบุคคลใหม่

	15: ยอมรับบุคคลใหม่หากค่าความฟิตของดอกใหม่ดีกว่าค่าปัจจุบัน

	16: ตั้ง t = t+1

17: ถ้า t > mazitr ให้ออกจากลูป

18: แสดงผลลัพธ์ที่ดีที่สุดออกมา

# สมาชิกผู้จัดทำ

    จัดทำโดยนักศึกษาสถาบันการจัดการปัญญาภิวัฒน์ (PIM) ชั้นปีที่ 3
    นายศิวกฤษฏิ์ กล้วยไม้เจริญ 6252500020
    https://www.facebook.com/profile.php?id=100010958970680
    
    นายภูริต เหล่ารุ่งเกียรติ 6252500127
    https://www.facebook.com/purit.luarungkiat
    
    นายพงษ์ปรีชา รัตนสร้อย 6252500283
    https://www.facebook.com/ktiger555/
    
    นายชินดนัย โสรบุตร 6252500526
    https://www.facebook.com/profile.php?id=100002221170767
    
    นายจิรสิน เทศรุ่งเรือง 6252500569
    https://www.facebook.com/nstang.jinnapot

| สร้างไฟล์ README  | https://dillinger.io/ |
### สามารถติดตามผลงานได้...https://github.com/tooe81948
