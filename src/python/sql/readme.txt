创建选课系统如下格式的表：

teacher:
id(PK),name,desc
class:
name(PK),teacherid(FK)
student:
id name age classid 

course:
name(PK),desc,teacherid(FK)

choose_course:
studentid(PK),courseid(PK),grade

student->course: 多对多 choose_course新表
student->class: 多对一
class->teacher: 多对一
course->teacher: 多对一

 