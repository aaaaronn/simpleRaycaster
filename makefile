default:
	g++ -o raycast ./src/main.cpp ./src/math.cpp ./src/object.cpp ./src/types.cpp ./src/sphere.cpp ./src/camera.cpp
	./raycast