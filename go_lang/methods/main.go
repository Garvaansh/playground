package main

import "fmt"

func main() {
	ansh := User{
		Name:     "Anshul",
		Age:      20,
		Email:    "ansh@xyz.com",
		isActive: false}

	ActiveStatus := ansh.GetStatus()
	fmt.Println("User status: ", ActiveStatus)
	fmt.Println("Curr email:", ansh.Email)
	
	// Won't actually change the struct object 
	// Go sends pass by value, not reference, 
	// so the method gets a copy of the struct, and changes it, but the original struct remains unchanged
	emailChanged := ansh.NewMail()
	if emailChanged {
		fmt.Println("New Email:", ansh.Email)
	} else {
		fmt.Println("Email is empty, cannot change")
	}
}

type User struct {
	Name     string
	Age      int
	Email    string
	isActive bool
}

func (u User) GetStatus() string {
	if u.isActive {
		return "Active"
	} else {
		return "Inactive"
	}
}

func (u User) NewMail() bool {
	if u.Email != "" {
		u.Email = "i_changed_email-hehe@xyz.com"
		fmt.Println("Inside method, new email is", u.Email)
		return true
	} else {
		return false
	}
}
