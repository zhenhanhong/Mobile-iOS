//
//  NetworkClient.h
//  StarCloud
//
//  Created by Steven.W on 16/6/6.
//  Copyright © 2016年 mac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworking.h"

@interface NetworkClient : NSObject

typedef void (^FinishBlock)(id responseObject);
@property (strong, nonatomic) FinishBlock finishBlock;

/**
 *  @author HYC
 *
 *  网络get请求
 *
 *  @param dict    键值对参数
 *  @param mname   传送路径
 *  @param DESkey  DES加密
 *  @param Fiblock 成功后调用方法块
 *  @param Fablock 失败后调用方法块
 */
-(void)getSimple_RequestWithData:(NSDictionary *)dict
                      Methodname:(NSString *)mname
                          DESkey:(NSString *)key
                              fi:(FinishBlock)Fiblock
                              fa:(FinishBlock)Fablock;

/**
 *  @author HYC
 *
 *  网络post请求
 *
 *  @param dict    键值对参数
 *  @param mname   传送路径
 *  @param DESkey  DES加密
 *  @param Fiblock 成功后调用方法块
 *  @param Fablock 失败后调用方法块
 */
-(void)postSimple_RequestWithData:(NSDictionary *)dict
                       Methodname:(NSString *)mname
                           DESkey:(NSString *)key
                               fi:(FinishBlock)Fiblock
                               fa:(FinishBlock)Fablock;
/**
 *  @author HYC
 *
 *  网络put请求
 *
 *  @param dict    键值对参数
 *  @param mname   传送路径
 *  @param DESkey  DES加密
 *  @param Fiblock 成功后调用方法块
 *  @param Fablock 失败后调用方法块
 */
-(void)putSimple_RequestWithData:(NSDictionary *)dict
                       Methodname:(NSString *)mname
                           DESkey:(NSString *)key
                               fi:(FinishBlock)Fiblock
                               fa:(FinishBlock)Fablock;
/**
 *  @author HYC
 *
 *  网络delete请求
 *
 *  @param dict    键值对参数
 *  @param mname   传送路径
 *  @param DESkey  DES加密
 *  @param Fiblock 成功后调用方法块
 *  @param Fablock 失败后调用方法块
 */
-(void)deleteSimple_RequestWithData:(NSDictionary *)dict
                       Methodname:(NSString *)mname
                           DESkey:(NSString *)key
                               fi:(FinishBlock)Fiblock
                               fa:(FinishBlock)Fablock;
/**
 * 上传日志
 */
-(void)postJson_RequestWithData:(id)json
                     Methodname:(NSString *)mname
                         DESkey:(NSString *)key
                             fi:(FinishBlock)Fiblock
                             fa:(FinishBlock)Fablock;
-(void)checkTime;
@end
