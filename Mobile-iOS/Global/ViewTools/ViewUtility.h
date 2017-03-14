//
//  ViewUtility.h
//  StarCloud
//
//  Created by mac on 16/6/2.
//  Copyright © 2016年 mac. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ViewUtility : NSObject

// 将UIColor变换为UIImage
+ (UIImage *)createImageWithColor:(UIColor *)color;
//
+ (UIView *)findFirstResponderBeneathView:(UIView*)view;
// 截屏+构图
+ (UIImage *)grabScreenImageWithIfTabController:(BOOL)ifTabController;
// 截屏
+ (UIImage *)grabScreen;
// 倒计时按钮
+ (void)drawCountDownButton:(UIButton *)button countTime:(int)countTime;
@end
