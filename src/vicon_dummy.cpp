#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "vicon_dummy");
  ros::NodeHandle node;

  tf::TransformBroadcaster br;
  tf::Transform transform;

  std::string worldFrame = "world";
  std::string frame = "frame";

  node.getParam("vicon_dummy_node/worldFrame", worldFrame);
  node.getParam("vicon_dummy_node/frame", frame);

  ros::Rate rate(10.0);
  while (node.ok()){
    transform.setOrigin( tf::Vector3(0.0, 2.0, 0.0) );
    transform.setRotation( tf::Quaternion(0, 0, 0, 1) );
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), worldFrame, frame));
    rate.sleep();
  }
  return 0;
};

