//
//  NotificationMacros.h
//  STWangzeping
//
//  Created by Steven.W on 16/5/30.
//  Copyright © 2016年 mac. All rights reserved.
//

#ifndef NotificationMacros_h
#define NotificationMacros_h


#endif /* NotificationMacros_h */

#pragma mark - Notification
// 切换院线相关标题
#define YX_GET_CHANGED                @"YX_GET_CHANGED"
// 切换影投相关标题
#define YT_GET_CHANGED                @"YT_GET_CHANGED"
// 修改影城标题
#define YC_GET_CHANGED                @"YC_GET_CHANGED"
// 修改影片标题
#define FILM_CHANGED_KEY              @"FILM_CHANGED_KEY"
// 控制是否选中日历标题
#define CALANDERTITLE_SELECTED_KEY    @"CALANDERTITLE_SELECTED_KEY"
// 控制切换关注影城按钮显示
#define REFRESH_FAVORCINEMA_KEY       @"REFRESH_FAVORCINEMA_KEY"
// 控制切换关注院线按钮显示
#define REFRESH_FAVORTHEATERCHAIN_KEY @"REFRESH_FAVORTHEATERCHAIN_KEY"
// 控制切换关注影投按钮显示
#define REFRESH_FAVORTHEATER_KEY      @"REFRESH_FAVORTHEATER_KEY"
// 存储用户信息完毕
#define SAVE_USERINFO_SUCCEED_KEY     @"SAVE_USERINFO_SUCCEED_KEY"

#pragma mark - UserDefaults
// 记录大盘首页影投票房信息
#define YT_BOXOFFICE_KEY          @"YT_BOXOFFICE_KEY"
// 记录大盘首页院线票房信息
#define YX_BOXOFFICE_KEY          @"YX_BOXOFFICE_KEY"
// 影城名字
#define TITLE_CINEMA_KEY          @"TITLE_CINEMA_KEY"
// 判断是否是授权登录
#define IF_AOTHURED_KEY           @"IF_AOTHURED_KEY"
#define AOTHURED_VALUE_GUEST      @"AOTHURED_VALUE_GUEST"
#define AOTHURED_VALUE_REGISTER   @"AOTHURED_VALUE_REGISTER"
#define AOTHURED_VALUE_ENTERPRISE @"AOTHURED_VALUE_ENTERPRISE"
// 影城和院线首页公用一个tabelView,涉及重用问题，在此处做记录
#define REUSED_TABEL_KEY          @"REUSED_TABEL_KEY"
// 存储记录用户搜索过的影城
#define USERCINEMAS_KEY           @"USERCINEMAS_KEY"
// 记录用户点击某个关注影城的model，用作首次初始化影城首页
#define FAVOUR_CINEMA_KEY         @"FAVOUR_CINEMA_KEY"
// 记录用户点击某个关注院线的model，用作首次初始化院线首页
#define FAVOUR_THEATERCHAIN_KEY   @"FAVOUR_THEATERCHAIN_KEY"
// 记录用户点击某个关注影投的model，用作首次初始化影投首页
#define FAVOUR_THEATER_KEY        @"FAVOUR_THEATER_KEY"
// 记录用户信息
#define USERINFO_KEY              @"USERINFO_KEY"
// 记录用户最后访问的院线
#define LATEST_ACCESS_THEATER_KEY @"LATEST_ACCESS_THEATER_KEY"
// 记录用户最后访问的影投
#define LATEST_ACCESS_YT_KEY      @"LATEST_ACCESS_YT_KEY"
// 记录用户最后访问的影城
#define LATEST_ACCESS_CINEMA_KEY  @"LATEST_ACCESS_CINEMA_KEY"
// 记录所有影城model数组
#define WHOLE_CINEMAS_KEY         @"WHOLE_CINEMAS_KEY"
// 记录所有影投model数组
#define WHOLE_FILMINVEST_KEY      @"WHOLE_FILMINVEST_KEY"
// 记录所有院线model数组
#define WHOLE_THEATERCHAIN_KEY    @"WHOLE_THEATERCHAIN_KEY"
// 记录所有影片model数组
#define WHOLE_FILMS_KEY           @"WHOLE_FILMS_KEY"
// 记录全局用户选择日期
#define CURRENT_DATE_KEY          @"CURRENT_DATE_KEY"
// 记录是否进入预售页面，分离日期
#define IFENTERED_PRESELL_KEY     @"IFENTERED_PRESELL_KEY"
// 记录用户选择的竟对模板类型
#define TEMPLATE_KEY              @"TEMPLATE_KEY"
// 记录当前系统版本
#define kAppVersionKey            @"kAppVersionKey"

#pragma mark - UserInfo
// 记录日志类型
#define LogType_Check             @"查询"
#define LogType_Modify            @"修改"
#define LogType_Delete            @"删除"
#define LogType_Share             @"分享"
// 记录日志时间
#define LogTime                   [DateUtil stringFromDate:[NSDate date] pattern:PATTERN_YMDHMS]

#define REFRESH_TOKEN_KEY         @"REFRESH_TOKEN_KEY"
#define ACCESS_TOKEN_KEY          @"ACCESS_TOKEN_KEY"
#define TIMETOGETREFSH            @"TIMETOGETREFSH"
#define TARDIC                    @"TARDIC"
//常用自定义字符串
#pragma mark - StringUse
    #define LOGTIMESTR @"LOGTIMESTR"
    #define NEWLOGTIME @"NEWLOGTIME"
    #define EXPIRES_IN @"EXPIRES_IN"
