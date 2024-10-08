# TWRP 3.7.0 for Samsung S3 Mini (golden)
---
<br>Yeah, <b>Real one</b>, works pretty fine.
<br>To get working gui you need to duplicate "gui_init();" line at [twrp.cpp](https://github.com/TeamWin/android_bootable_recovery/blob/android-9.0/twrp.cpp#L121)
<br>
<br>Based on branch "android-9.0" of TWRP + [Minimal manifest](https://github.com/minimal-manifest-twrp/platform_manifest_twrp_omni), branch "twrp-6.0"
<br>Using <b>kernel 3.4.67</b>, based on [3liteking148 work](https://github.com/3liteking148/android_kernel_samsung_golden-3.4), now based on [edited variant](https://github.com/jiganomegsdfdf/android_kernel_samsung_golden), branch "3.4-and10binder"
<br>Initial device tree got from [andi34 repo](https://github.com/andi34/android_device_samsung_golden), branch "twrp-3.0"
<br>Local manifests [here](https://github.com/jiganomegsdfdf/local_manifests_golden), branch "twrp-3.7.0"
