#pragma once

#include "mayaMVG/core/MVGCamera.h"
#include "mayaMVG/core/MVGPointCloud.h"
#include "mayaMVG/core/MVGMesh.h"
#include <vector>
#include <map>

namespace mayaMVG {
		
class MVGProject : public MVGNodeWrapper {
	
	public:
		MVGProject(const std::string& name = "mayaMVG");
		MVGProject(const MDagPath& dagPath);
		virtual ~MVGProject();	
		
	public:
		virtual bool isValid() const;
	
	public:
		static MVGProject create(const std::string& name);
		static std::vector<MVGProject> list();

	public:
		bool load(const std::string& projectDirectoryPath);
		bool loadCameras(const std::string& projectDirectoryPath);
		bool loadPointCloud(const std::string& projectDirectoryPath);
	
	public:
		// filesystem
		std::string projectDirectory() const;
		void setProjectDirectory(const std::string&) const;
        bool isProjectDirectoryValid(const std::string&) const;
		// nodes
		std::vector<MVGCamera> cameras() const;
		std::vector<MVGPointCloud> pointClouds() const;
        void selectCameras(std::vector<std::string> cameraNames) const;

	public:
		// openMVG node names
		static std::string _CLOUD;
		static std::string _MESH;
		static std::string _PROJECT;
        // dynamic attributes
        static MString _PROJECTPATH;
        static std::string _cameraRelativeDirectory;
        static std::string _imageRelativeDirectory;
        static std::string _cameraRelativeFile;
        static std::string _pointCloudRelativeFile;
};

} // mayaMVG
