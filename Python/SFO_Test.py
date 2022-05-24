import math
sensor = [1753,1793,1713,1752]
p = 0.0 ; si = [] ; di = [] ; X = [] ; posX = 90 ; posY = 120
P=1

for i in sensor:
  try:
    si.append(int(max(sensor) - i) / abs(max(sensor) - i))
  except:
    si.append(p)
d_max = abs(math.radians(max(sensor)) + math.radians(min(sensor))) / 2*len(sensor)

for i,j in enumerate(sensor):
  di.append(int((math.radians(d_max%180) * (P*((sensor[i] + sensor[i-1]) * abs(sensor[i] + sensor[i-1])))))%180)
for i,j,z in zip(sensor,di,si):
  X.append(int(i+j*z)%180)

print(si)
print(d_max)
print(di)
print(X)
print("Y = {0} , X = {1}".format((abs(X[0]-X[3])/4) ,(abs(X[1]-X[2])/4)))
print("OLD Y = {0} , X = {1}".format(posY,posX))


if ( si.count(0) > 2 and si[1] == 0 ) or si[1] == 0 :
  print("X-")
  posX = posX+((abs(X[1]-X[2])/4)*(-1))
else:
  print("X")
  posX = posX+(abs(X[1]-X[2])/4)

if ( si.count(0) > 2 and si[3] == 0 ) or si[3] == 0 :
  print("Y-")
  posY = posY+((abs(X[0]-X[3])/4)*(-1))
else:
  print("Y")
  posY = posY+(abs(X[0]-X[3])/4)

print("New Y = {0} , X = {1}".format(posY,posX))