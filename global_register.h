#ifndef GLOBAL_REGISTER_H
#define GLOBAL_REGISTER_H

#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/keypoints/harris_3d.h>
#include <pcl/features/fpfh.h>
#include <pcl/features/fpfh_omp.h>
#include <pcl/registration/icp.h>
#include <pcl/registration/ia_ransac.h>
#include <pcl/io/pcd_io.h>

#include "dualquat/dual_quaternions.h"
#include "dualquat/mesh.h"
#include "dualquat/math3d.h"

#include <Eigen/Dense>

typedef pcl::PointXYZ Point;

class GlobalDQReg {
  public:
    GlobalDQReg();
    void pairwiseRegister();
    void runDQDiffusion();
    void saveAllKeyPoints(std::string);

  private:
    std::vector<pcl::PointCloud<Point>::Ptr > bunny_clouds_;
    std::vector<Eigen::Matrix4f> pairwise_transformations_;

    void loadPCDFiles();
    void saveCloudKeyPoints(std::string, int);
    void getTransformOfPair(pcl::PointCloud<Point>::Ptr& cloud_1, pcl::PointCloud<Point>::Ptr& cloud_2, Eigen::Matrix4f& tranform);

};

#endif
