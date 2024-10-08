/*
   Copyright (C) 2007, The Android Open Source Project
   Copyright (c) 2016, The CyanogenMod Project
   Copyright (c) 2023, The LineageOS Project
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include <sys/stat.h>
#include <sys/types.h>
/*#include <filesystem.h>
#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android-base/strings.h>*/
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

std::string kPartitionMap[] = {
        "", "", "mastertoc", "pit", "md5hdr", "steboot1", "steboot2", "dnt", 
		"reserved", "cspafs", "cspafs2", "efs", "modemfs", "modemfs2", 
		"fota", "iplmodem", "modem", "loke4", "2ndloke4", "param", 
		"boot", "recovery", "system", "cache", "vendor", "userdata"
};
void fix_symlinks() {
    const std::string kPathPrefix = "/dev/block/mmcblk0p";
    const std::string kLinkPrefix = "/dev/block/platform/hi_mci.0/by-name";
    if (access(kLinkPrefix.c_str(), F_OK) != 0) {
		mkdir("/dev/block/platform/", 0755);
		INFO("/dev/block/platform/");
		mkdir("/dev/block/platform/hi_mci.0/", 0755);
		INFO("/dev/block/platform/hi_mci.0/");
		mkdir("/dev/block/platform/hi_mci.0/by-name", 0755);
		INFO("/dev/block/platform/hi_mci.0/by-name");
    }
    for (int i = 2; i < sizeof(kPartitionMap)/sizeof(kPartitionMap[0]); ++i) {
        std::string path = kPathPrefix + std::to_string(i);
        std::string link = kLinkPrefix + "/" + kPartitionMap[i];
		symlink(path.c_str(), link.c_str());
		INFO(link.c_str());
    }
}

void vendor_load_properties() {
	INFO("Doing evil stuff");
    fix_symlinks();
	INFO("Evil stuff done");
}