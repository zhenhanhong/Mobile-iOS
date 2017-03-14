//
//  APIStringMacros.h
//  STWangzeping
//
//  Created by mac on 16/5/30.
//  Copyright © 2016年 mac. All rights reserved.
//

#ifndef APIStringMacros_h
#define APIStringMacros_h


#endif /* APIStringMacros_h */

//#if DEBUG

#pragma mark - Main_Api_Define_DEBUG

#if DEBUG
    // 除oauth以外，通用接口地址
    #define SERVER_URI @"http://101.200.228.15/api"
    // h5页面地址
    #define H5_CHART_FORM_WEB @"http://101.200.228.15/app/echarts.html?"
#else
    #define SERVER_URI @"http://nebula.cfilmcloud.com/api"
    #define H5_CHART_FORM_WEB @"http://101.200.205.3/app/echarts.html?"
#endif
    // oauth通用接口地址
    #define SERVER_URI_OAUTH @"http://nebula.cfilmcloud.com/oauth"
    #define SERVER_USERPSD @"nebula-ios:d0f400535a399d70be918de9f6180d91"
    // 游客用户名密码
    #define GUEST_USERNAME @"GUEST"
    #define GUEST_PASSWORD @"123456"
    //
    #define HEADER_SECRET @"Authorization"
    #define HEADER_CONTENT [NSString stringWithFormat:@"Bearer %@",UserDefaultsGetObj(ACCESS_TOKEN_KEY)]
//#else

#pragma mark - Main_Api_Define_Release

//#endif

#pragma mark - Sub_Api_Define
#pragma mark - 登录
// 游客登录授权
#define guestLogin @"/token"
// 登录短信发送
#define smsLogin   @"/send/"
// 注册短信发送
#define registSms  @"/register/verify/"
// 注册完成
#define registDone @"/register"

#pragma mark - 首页
// 获取指定日期的大盘
#define getDapanInfo        @"/home/dapan"
// 获取各院线(影投)的票房情况列表
#define getBoxOfficeSummary @"/home/boxofficesummary"
// 获取数据更新时间，在此之前显示前天大盘，之后显示昨日大盘
#define getUpdateTime       @"/home/updatetime"

#pragma mark - 院线
// 列出所有院线/影投
#define getTheaterChainList           @"/theaterchain/list"
// 获取院线/影投票房统计
#define getTheaterChainBoxOffice      @"/theaterchain/boxoffice"
// 获取院线/影投影城影厅数量统计
#define getTheaterChainCount          @"/theaterchain/theatercount"
// 获取院线/影投在映影片票房列表
#define getTheaterChainFilms          @"/theaterchain/films"
// 获取院线/影投某个在映影片的票房历史数据
#define getTheaterChainFilmHistory    @"/theaterchain/filmhistory"
// 获取院线/影投城市票房列表
#define getTheaterChainCities         @"/theaterchain/cities"
// 获取院线/影投辖区票房列表
#define getTheaterChainAreas          @"/theaterchain/areas"
// 获取院线/影投影片预售列表
#define getTheaterChainPresell        @"/theaterchain/presell"
// 获取院线/影投影片预售历史
#define getTheaterChainPresellHistory @"/theaterchain/presellhistory"
// 获取院线/影投影片渠道票房列表 - 放映日
#define getTheaterChainShowday        @"/theaterchain/channels/showday"
// 获取院线/影投影片渠道票房列表 - 订票日
#define getTheaterChainBookday        @"/theaterchain/channels/bookday"
// 热门院线
#define getHotTheaterChainsList       @"/theaterchain/hot"
// 按城市查询所有影城的票房
#define getCitytheatersList           @"/theaterchain/citytheaters"
// 院线|影投按大区查询所有城市票房
#define getAreacitiesList             @"/theaterchain/areacities"

#pragma mark - 影城
// 列出所有影城
#define getTheaterList             @"/theater/list"
// 获取影城基本信息
#define getTheaterInfo             @"/theater/info/"
// 获取影城票房
#define getTheaterBoxOffice        @"/theater/boxoffice"
// 获取影城在映影片票房列表
#define getTheaterFilms            @"/theater/films"
// 获取影城某个在映影片的票房历史数据
#define getTheaterFilmsHistoryInfo @"/theater/filmhistory"
// 获取影城竞争对手票房列表
#define getTheaterRivals           @"/theater/rivals"
// 获取竞对所有上映的影片
#define getTheaterRivalFilms       @"/theater/rivalfilms"
// 获取影城影片预售列表
#define getTheaterPresell          @"/theater/presell"
// 获取影城影片预售历史
#define getTheaterPresellHistory   @"/theater/presellhistory"
// 获取影城影片渠道票房列表 - 放映日
#define getTheaterShowday          @"/theater/channels/showday"
// 获取影城影片渠道票房列表 - 订票日
#define getTheaterBookday          @"/theater/channels/bookday"

#pragma mark - 我的
// 获取用户信息
#define getMeInfo                          @"/me/info"
// 列出用户收藏的影城
#define getMeCollectionsCinema             @"/me/collection/theater"
// 列出用户收藏的院线
#define getMeCollectionsTheaterchain       @"/me/collection/theaterchain"
// 列出用户收藏的影投
#define getMeCollectionsFilminvest         @"/me/collection/filminvest"
// 提交意见反馈
#define getMeComment                       @"/me/comment"
// 上传使用日志
#define getMeLogs                          @"/me/logs"
// 查询用户默认影投
#define meDefaultFilminvest                @"/me/default/filminvest"
// 查询用户默认院线
#define meDefaultTheaterchain              @"/me/default/theaterchain"
// 查询用户默认影城
#define meDefaultTheater                   @"/me/default/theater"
// 配置/获取自定义竞对模板
#define meRivalTemplate                    @"/me/rivaltemplate/"
// 返回该用户定义过竞对的影城列表
#define meRivalTemplates                   @"/me/rivaltemplates"

#pragma mark - 影片信息
// 列出所有影片
#define getFilmList     @"/film/list"
// 获取影片的基本信息
#define getFilmBaseInfo @"/film/"
// 热门影片
#define getHotFilmsList @"/film/hot"

#pragma mark - 第三方渠道参数
// 友盟APPKEY
// @"57eb308467e58ef15b0008e5"
#define UMeng_APPKEY     @"575cc9dc67e58e4725000f77"
// 微信APPID
#define Wechat_APPID     @"wx8e281b4633480626"
// 微信APPSECRET
#define Wechat_APPSECRET @"c82c6b85f92ab2a4a4a3685d8a8ae820"
// 腾讯APPID
#define Tencent_APPID    @"1105435855"
// 腾讯APPKEY
#define Tencent_APPKEY   @"D5muq77kvdviwsbu"
// 新浪APPKEY
#define Sina_APPKEY      @"2626353284"
// 新浪APPSECRET
#define Sina_APPSECRET   @"80e56b36a44f1eb00822f0441ced6f24"
// 星云app下载链接
// @"https://itunes.apple.com/us/app/xing-yun-piao-fang-fen-xi/id1123399435?l=zh&ls=1&mt=8"
#define iTunes_Connect_Url @"https://itunes.apple.com/cn/app/xing-yun-piao-fang-fen-xi/id1123399435?mt=8"
//
#define Phone_Number     @"400-080-1661"

