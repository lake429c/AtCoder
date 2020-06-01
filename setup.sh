sudo mv /etc/apt/apt.conf.d/50appstream /etc/apt/apt.conf.d/50appstream.disable
sudo apt update -y
sudo apt upgrade -y
sudo mv /etc/apt/apt.conf.d/50appstream.disable /etc/apt/apt.conf.d/50appstream
sudo apt update -y
sudo rm /var/crash/*
sudo sed -i 's/enabled=1/enabled=0/g' /etc/default/apport

tar -xvzf ./l_openvino_toolkit_p_2020.2.120.tgz
./l_openvino_toolkit_p_2020.2.120/install.sh
sudo -E ./intel/openvino/install_dependencies/install_openvino_dependencies.sh
source /home/hoge/intel/openvino/bin/setupvars.sh
echo source /home/hoge/intel/openvino/bin/setupvars.sh >> .bashrc
cd ./intel/openvino/deployment_tools
./model_optimizer/install_prerequisites/install_prerequisites.sh
./demo/demo_squeezenet_download_convert_run.sh
./demo/demo_security_barrier_camera.sh
cd ~
cd ./inference_engine_demos_build/intel64/Release
./security_barrier_camera_demo -d CPU -d_va CPU -d_lpr CPU -i /home/hoge/intel/openvino/deployment_tools/demo/car_1.bmp -m /home/hoge/openvino_models/ir/intel/vehicle-license-plate-detection-barrier-0106/FP16/vehicle-license-plate-detection-barrier-0106.xml -m_lpr /home/hoge/openvino_models/ir/intel/license-plate-recognition-barrier-0001/FP16/license-plate-recognition-barrier-0001.xml -m_va /home/hoge/openvino_models/ir/intel/vehicle-attributes-recognition-barrier-0039/FP16/vehicle-attributes-recognition-barrier-0039.xml
cd ~
cd ./inference_engine_samples_build/intel64/Release
./classification_sample_async -i /home/hoge/intel/openvino/deployment_tools/demo/car.png -m /home/hoge/openvino_models/ir/public/squeezenet1.1/FP16/squeezenet1.1.xml -d CPU
cd ~
