//
//  DimensMacros.h
//  STWangzeping
//
//  Created by mac on 16/5/30.
//  Copyright © 2016年 mac. All rights reserved.
//
#import "SCAppDelegate.h"
#ifndef DimensMacros_h
#define DimensMacros_h

// APPDELEGATE
#define appDelegate ((SCAppDelegate *)([[UIApplication sharedApplication] delegate]))

// 状态栏高度
#define STATUS_BAR_HEIGHT     20
// NavBar高度
#define NAVIGATION_BAR_HEIGHT 44
// 状态栏 ＋ 导航栏 高度
#define STATUS_AND_NAVIGATION_HEIGHT ((STATUS_BAR_HEIGHT) + (NAVIGATION_BAR_HEIGHT))

// 热点栏高度
#define HOTSPOT_STATUSBAR_HEIGHT 20
// 工具栏（UINavigationController.UIToolbar）高度
#define TOOLBAR_HEIGHT           44
// 标签栏（UITabBarController.UITabBar）高度
#define TABBAR_HEIGHT            49
// 热点栏高度
#define HOTSPOT_STATUSBAR_HEIGHT 20
// APP_STATUSBAR_HEIGHT=STATUS_BAR_HEIGHT+[HOTSPOT_STATUSBAR_HEIGHT]
#define APP_STATUSBAR_HEIGHT                (CGRectGetHeight([UIApplication sharedApplication].statusBarFrame))
// 根据APP_STATUSBAR_HEIGHT判断是否存在热点栏
#define IS_HOTSPOT_CONNECTED                (APP_STATUSBAR_HEIGHT==(STATUS_BAR_HEIGHT+HOTSPOT_STATUSBAR_HEIGHT)?YES:NO)
// 无热点栏时，标准系统状态栏高度+导航栏高度
#define NORMAL_STATUS_AND_NAV_BAR_HEIGHT    (STATUS_BAR_HEIGHT+NAVIGATION_BAR_HEIGHT)
// 实时系统状态栏高度+导航栏高度，如有热点栏，其高度包含在APP_STATUSBAR_HEIGHT中。
#define STATUS_AND_NAV_BAR_HEIGHT                    (APP_STATUSBAR_HEIGHT+NAVIGATION_BAR_HEIGHT)

// 屏幕 rect
#define SCREEN_RECT ([UIScreen mainScreen].bounds)

#define kScreenWidth [[UIScreen mainScreen] bounds].size.width

#define kScreenHeight [[UIScreen mainScreen] bounds].size.height

#define CONTENT_HEIGHT (SCREEN_HEIGHT - NAVIGATION_BAR_HEIGHT - STATUS_BAR_HEIGHT)

// 屏幕分辨率
#define SCREEN_RESOLUTION (SCREEN_WIDTH * SCREEN_HEIGHT * ([UIScreen mainScreen].scale))

// 机型
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) :       NO)
#define iPhone4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) :        NO)
#define iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) :       NO)
#define iPhone6_Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

// 广告栏高度
#define BANNER_HEIGHT     215

#define STYLEPAGE_HEIGHT  21

#define SMALLTV_HEIGHT    77

#define SMALLTV_WIDTH     110

#define FOLLOW_HEIGHT     220

#define SUBCHANNEL_HEIGHT 62


#endif /* DimensMacros_h */
