#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>

#include <pylon_camera/pylon_camera_node.h>

namespace pylon_camera
{

class PylonCameraNodelet : public nodelet::Nodelet
{
public:
    PylonCameraNodelet()
    {
    }
    ~PylonCameraNodelet()
    {
    }

    void onInit(void)
    {
        node_.reset(new pylon_camera::PylonCameraNode(getPrivateNodeHandle(), getMTNodeHandle()));
    }

private:
    boost::shared_ptr<pylon_camera::PylonCameraNode> node_;
};

} // namespace pylon_camera

PLUGINLIB_DECLARE_CLASS(pylon_camera, PylonCameraNodelet, pylon_camera::PylonCameraNodelet, nodelet::Nodelet);
