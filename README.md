# TWRP 3.7.0 for Samsung S3 Mini (golden)
<br>Yeah, <b>REAL ONE</b>, works fine.
<br>
<br>Features: 
<br>1.Mounting "HIDDEN" partition as "vendor" (for future usage).
<br>2.Now we have /dev/block/bootdevice/by-name, made for stock partition table (only indexes matter), can be edited [here](https://github.com/jiganomegsdfdf/android_device_samsung_golden/blob/android-9.0-twrp-3.7.0/init/init_golden.cpp#L49).
<br>3.Will start with 99% chance (unlike to others recoveries), <b>if "HIDDEN" partition is valid</b>.
<br>
<br><b>CAUTION: Should be used with [u-boot](https://github.com/stericsson-mainline/u-boot/releases). Because REBOOT USING POWER BUTTON can DAMAGE EFS/PRELOAD/HIDDEN/SYSTEM partitions, make sure to always have backup.</b>
<br>P.S.You can also just format them (seems like only "HIDDEN" partition requires format to boot) to get back in working state
<br>
<br>
<br>
<br><b>DEV INFO</b>
<br>To get working gui you need to duplicate "gui_init();" line at [twrp.cpp](https://github.com/TeamWin/android_bootable_recovery/blob/android-9.0/twrp.cpp#L121)
<br>Based on branch "android-9.0" of TWRP + [Minimal manifest](https://github.com/minimal-manifest-twrp/platform_manifest_twrp_omni), branch "twrp-6.0"
<br>Using <b>kernel 3.4.67</b>, based on [3liteking148 work](https://github.com/3liteking148/android_kernel_samsung_golden-3.4), now based on [edited variant](https://github.com/jiganomegsdfdf/android_kernel_samsung_golden), branch "3.4-and10binder"
<br>Initial device tree got from [andi34 repo](https://github.com/andi34/android_device_samsung_golden), branch "twrp-3.0"
<br>Local manifests [here](https://github.com/jiganomegsdfdf/local_manifests_golden), branch "twrp-3.7.0"
