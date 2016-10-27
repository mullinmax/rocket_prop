


class rocket {
  float mass;
  float len;
  float max_thrust;
  float size;
  float theta_x;
  float theta_y;
  float ang_vel_x;
  float ang_vel_y;
  float prop_n_theta;
  float prop_e_theta;
  float prop_s_theta;
  float prop_w_theta;
  boolean prop_n_on;
  boolean prop_e_on;
  boolean prop_s_on;
  boolean prop_w_on;
  float force_n;
  float force_e;
  float force_s;
  float force_w;
  float pos_tol;
  float vel_tol;
  rocket(float m, float l, float t) {
    mass = m;
    len = l;
    max_thrust = t;
    size = 100;
    //theta_x = 0;
    //theta_y = 0;
    theta_x = 0;
    theta_y = 0;
    ang_vel_x = 0;
    ang_vel_y = 0;


    prop_n_theta = 0;
    prop_e_theta = 0;
    prop_s_theta = 0;
    prop_w_theta = 0;
    prop_n_on = false;
    prop_e_on = false;
    prop_s_on = false;
    prop_w_on = false;
    pos_tol = PI/18;
    vel_tol = .0005;
  }


  void update() {
    theta_x = theta_x % (2*PI);
    theta_y = theta_y % (2*PI);
    ang_vel_x -= .00075 * sin(theta_x);
    ang_vel_y -= .00075 * sin(theta_y);


    stabilize();
    theta_x += ang_vel_x;
    theta_y += ang_vel_y;
    if (prop_n_on) {
      ang_vel_y += -.00005;
      prop_n_theta += .1;
    }
    if (prop_e_on) {
      ang_vel_x += -.00005;
      prop_e_theta += -0.1;
    }
    if (prop_s_on) {
      ang_vel_y += .00005;
      prop_s_theta += 0.1;
    }
    if (prop_w_on) {
      ang_vel_x += .00005;
      prop_w_theta += -0.1;
    }
  }


  void pull() {
    ang_vel_x -= .00002*(width / 2.0 - mouseX);
    ang_vel_y += .00002*(height / 2.0 - mouseY);
  }


  void stabilize() {
    if (theta_y*theta_y + theta_x*theta_x < pos_tol*pos_tol && ang_vel_y*ang_vel_y + ang_vel_x*ang_vel_x < vel_tol*vel_tol) {
      prop_n_on = false;
      prop_s_on = false;
      prop_e_on = false;
      prop_w_on = false;
    } else {
      if (theta_x > 0) {
        if (ang_vel_x > 0) {
          prop_e_on = true;
          prop_w_on = false;
        } else {
          prop_e_on = false;
          prop_w_on = true;
        }
      } else  if (theta_x < 0) {
        if (ang_vel_x > 0) {
          prop_e_on = true;
          prop_w_on = false;
        } else {
          prop_e_on = false;
          prop_w_on = true;
        }
      } else {
        prop_e_on = false;
        prop_w_on = false;
      }
      if (theta_y > 0) {
        if (ang_vel_y > 0) {
          prop_n_on = true;
          prop_s_on = false;
        } else {
          prop_n_on = false;
          prop_s_on = true;
        }
      } else if (theta_y < 0) {
        if (ang_vel_y > 0) {
          prop_n_on = true;
          prop_s_on = false;
        } else {
          prop_n_on = false;
          prop_s_on = true;
        }
      } else {
        prop_n_on = false;
        prop_s_on = false;
      }
    }
    //if(theta_x < 0 && ang_vel_x < 0){
    //  ang_vel_x += force_e + ang_vel_x;
    //}else{
    //  ang_vel_x = -ang_vel_x / 5;
    //}
    //if(theta_y < 0){
    //  ang_vel_y = -ang_vel_y  / 5;
    //}else{
    //  ang_vel_y = ang_vel_y * -1 / 5;
    //}
  }


  void display() {
    rectMode(CENTER);
    fill(150);
    strokeWeight(4);
    stroke(10);
    pushMatrix();
    translate(width/2, height/2, -len);
    translate(len*sin(theta_x), len*sin(-theta_y), len*sin(sqrt(theta_x*theta_x+theta_y*theta_y)));
    //rotateX(-theta_y);
    //rotateY(-theta_x);


    translate(0, 0, -len);
    box(size);
    line(0, 0, 0, 0, 1, len);
    stroke(0);


    pushMatrix(); //North
    fill(255);
    translate(0, -size*.75, 0);
    rotateY(prop_n_theta);
    box(size, size / 6.0, size / 6.0);
    popMatrix();


    fill(150);


    pushMatrix(); //East
    rotateZ(PI/2);
    translate(0, -size*.75, 0);
    rotateY(prop_e_theta);
    box(size, size / 6.0, size / 6.0);
    popMatrix();


    pushMatrix(); //South
    rotateZ(PI);
    translate(0, -size*.75, 0);
    rotateY(prop_s_theta);
    box(size, size / 6.0, size / 6.0);
    popMatrix();


    pushMatrix(); //West
    rotateZ(-PI/2);
    translate(0, -size*.75, 0);
    rotateY(prop_w_theta);
    box(size, size / 6.0, size / 6.0);
    popMatrix();


    popMatrix();


    strokeWeight(2);
    stroke(0);
  }
}