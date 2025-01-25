let myName: "anuj" = "anuj" // means it can only be "anuj"  
const myName22 = "Bob"

type UserRole = "contributer" | "admin" | "member" | "guest"

type User = {
    id: number
    username: string
    role: UserRole
}
//partial type
type updatedUser = Partial<User>
// utility type
// type updatedUser = {
//     id?: number
//     username?: string
//     role?: UserRole
// }
let nextUserId = 1

const users: User[] = [
    { id: nextUserId++, username: "anuj", role: "guest" },
    { id: nextUserId++, username: "mohit", role: "admin" },
    { id: nextUserId++, username: "priyanka", role: "member" },
]
function fetchUserDetail(username: string): User {
    const user = users.find(u => u.username === username)
    if (!user) {
        throw new Error(`user with username ${username} not found`)
    }
    return user
}

let value: any = 2 // typescript checking is off
value.touppercase()

// do not use any in  typescript 
// only use when you are changing code from js to ts and you have less time

function updateUser(id: number, updates: updatedUser): User | undefined {
    const user = users.find(u => u.id === id)
    if (!user) {
        console.error(`user with id ${id} not found`)
        return
    }
    return Object.assign(user, updates)
}

updateUser(1, { role: "admin" })

// | means union
// omit types - the string has the value we like to not have and rest value are there
// for multiple string example ---  Omit<User,"id" | "role">
function addNewUser(newUser: Omit<User,"id">): User {
    const user: User = { ...newUser, id: nextUserId++ }

    users.push(user);
    return user
}