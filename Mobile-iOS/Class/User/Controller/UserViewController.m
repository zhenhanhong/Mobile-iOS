//
//  UserViewController.m
//  Mobile-iOS
//
//  Created by zhenhh on 2017/3/10.
//  Copyright © 2017年 zhenhh. All rights reserved.
//

#import "UserViewController.h"
#import "UserTableViewCell.h"
@interface UserViewController ()<UITableViewDelegate,UITableViewDataSource>
@property (weak, nonatomic) IBOutlet UITableView *tableview;

@end

@implementation UserViewController

- (void)viewDidLoad {
    [super viewDidLoad];

}
-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UserTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"usercell"];


    return cell;
}
- (IBAction)push:(id)sender {
    UIStoryboard *storyBoard = [UIStoryboard storyboardWithName:@"Loginstoryborad" bundle:nil];
    [self presentViewController:[storyBoard instantiateInitialViewController] animated:YES completion:nil];
}
-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return 10;
}
@end
