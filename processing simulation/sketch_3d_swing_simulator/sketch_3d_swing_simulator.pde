rocket test;
void setup() {
  size(900, 900, P3D);
  test = new rocket(30, 600, 30);
  stroke(255);
  strokeWeight(8);
  frameRate(70);
}


void draw() {
  print(frameRate);
  print("\n");
  background(29, 222, 43);
  test.update();
  test.display();
}
void mousePressed() {
  test.pull();
}