//
//  UtilsMacros.h
//  STWangzeping
//
//  Created by mac on 16/5/30.
//  Copyright © 2016年 mac. All rights reserved.
//

#ifndef UtilsMacros_h
#define UtilsMacros_h
// 导航栏标题类型区分
typedef enum Navigation_TitleView_Type {
    SCNavigationTitleViewType_Normal    = 1,
    SCNavigationTitleViewType_ImageMix  = 2,
    SCNavigationTitleViewType_SubTitle  = 3,
    SCNavigationTitleViewType_ClickBtn  = 4,
    SCNavigationTitleViewType_SearchBar = 5,
    SCNavigationTitleViewType_Segment   = 6,
}Navigation_TitleView_Type;
// 电影数据详情页面票房/场次/人次/票价区分
typedef enum DataInfoType {
    SCDataInfoType_Boxoffice            = 1,
    SCDataInfoType_Rounds               = 2,
    SCDataInfoType_Tickets              = 3,
    SCDataInfoType_Price                = 4,
}DataInfoType;
// 预售详情页面分别从影城，院线，影投进入标记
typedef enum SourceType {
    SCSourceType_TheaterChain           = 1,
    SCSourceType_Theater                = 2,
    SCSourceType_Cinema                 = 3,
}SourceType;
// 区分登录渠道
typedef enum LoginType {
    NBLLoginTypeGuest                   = 1,
    NBLLoginTypeUser                    = 2,
    NBLLoginTypeAutoLogin               = 3,
}LoginType;
#ifdef DEBUG
    #define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
    #define NSLog(FORMAT, ...) fprintf(stderr,"\nfunction:%s line:%d content:%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
    #define DLog(...)
    #define NSLog(FORMAT, ...);
#endif

// 存储本地数据 - NSUserDefaults
#define UserDefaults                    [NSUserDefaults standardUserDefaults]
#define UserDefaultsSetObj(obj,key)     [UserDefaults setObject:obj forKey:key]; [UserDefaults synchronize];
#define UserDefaultsGetObj(key)         [UserDefaults objectForKey:key]

#define UserDefaultsSetObjData(obj,key) [UserDefaults setObject:[NSKeyedArchiver archivedDataWithRootObject:obj] forKey:key]; [UserDefaults synchronize];
#define UserDefaultsGetObjData(key)     [NSKeyedUnarchiver unarchiveObjectWithData:[UserDefaults objectForKey:key]]
#define UserDefaultsRemoveObject(key)   [UserDefaults removeObjectForKey:key];

//System version utils

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)
#define SYSTEM_VERSION  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

//************************ 设置颜色******************************************************
// 获取RGB颜色
#define COLOR(R,G,B,A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]
// 随机RGB颜色
#define LFPRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]
// 星云数据app标准金色
#define kStarCloud_MainColor [UIColor colorWithRed:227/255.0f green:189/255.0f blue:105/255.0f alpha:1]
// 浮动率下降绿色
#define kDecline_GreenColor  [UIColor colorWithRed:17/255.0f green:174/255.0f blue:39/255.0f alpha:1]
// 浮动率上升红色
#define kIncrease_RedColor   [UIColor colorWithRed:236/255.0f green:44/255.0f blue:44/255.0f alpha:1]
//clear背景颜色(清除背景色)
#define ClearColor     [UIColor clearColor]
//红色背景色
#define RED_Color      [UIColor redColor]
//绿色背景色
#define GREEN_Color    [UIColor greenColor]
//黑色背景色
#define BLACK_Color    [UIColor blackColor]
//白色背景色
#define WHITE_Color    [UIColor whiteColor]
//灰色背景色
#define GRAY_Color     [UIColor grayColor]
//深灰色
#define DARK_GRAY      [UIColor darkGrayColor]
//浅灰色
#define LIGHT_GRAY     [UIColor lightGrayColor]
//青色
#define CYAN_Color      [UIColor cyanColor]
//黄色
#define YELLOW_Color    [UIColor yellowColor]
//品红色
#define MAGENTA_Color   [UIColor magentaColor]
//橙色
#define ORANGE_Color    [UIColor orangeColor]
//紫色
#define PURPLE_Color    [UIColor purpleColor]
//布朗色
#define BROWN_Color     [UIColor brownColor]
//蓝色
#define BLUE_Color     [UIColor blueColor]

//************************ 设置颜色******************************************************

//************************ 设置 view 圆角和边框*******************************************
/*
 设置 view 圆角和边框
 */
#define ViewBorderRadius(View, Radius, Width, Color,Bounds)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:(Bounds)];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

//************************ 设置 view 圆角和边框*******************************************

// 数据异常文字展示
#define API_ERROR @"网络异常，请稍后再试"
// APP_NAME
#define APP_NAME @"星云票房分析"
// 接口提示信息显示延时时间
#define Tip_Delay 1.2f

#define IsPortrait ([UIApplication sharedApplication].statusBarOrientation == UIInterfaceOrientationPortrait || [UIApplication sharedApplication].statusBarOrientation == UIInterfaceOrientationPortraitUpsideDown)

#define IsNilOrNull(_ref)   (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]))

// 角度转弧度
#define DEGREES_TO_RADIANS(d) (d * M_PI / 180)

// 大于等于7.0的ios版本
#define iOS7_OR_LATER SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")

// 大于等于8.0的ios版本
#define iOS8_OR_LATER SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0")

// iOS6时，导航VC中view的起始高度
#define YH_HEIGHT (iOS7_OR_LATER ? 64:0)

// 获取系统时间戳
#define getCurentTime [NSString stringWithFormat:@"%ld", (long)[[NSDate date] timeIntervalSince1970]]


#endif /* UtilsMacros_h */
